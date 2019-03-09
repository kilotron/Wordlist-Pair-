// Core.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "Core.h"

using namespace std;

int Core::gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop)
{
	return gen_chain(words, len, result, head, tail, enable_loop, false);
}

int Core::gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop)
{
	return gen_chain(words, len, result, head, tail, enable_loop, true);
}

int Core::gen_chain(char * words[], int len, char * result[], char head,
	char tail, bool enable_loop, bool isWeighted)
{
	WordGraph g(words, len);
	Path *path;

	if (!enable_loop && g.IsCyclic()) {
		throw exception("Cycle detected.");
	}

	if (head == 0 && tail == 0) {
		path = g.LongestPath(isWeighted);
	}
	else if (head == 0 && isalpha(tail)) {
		path = g.LongestPathTo(tail, isWeighted);
	}
	else if (isalpha(head) && tail == 0) {
		path = g.LongestPathFrom(head, isWeighted);
	}
	else if (isalpha(head) && isalpha(tail)) {
		path = g.LongestPathBetween(head, tail, isWeighted);
	}
	else {
		throw exception("Illegal parameter.");
	}

	if (path == nullptr || path->WordCount() < 2) {
		return 0;
	}

	int wordCount = path->WordCount();
	for (int i = 0; i < wordCount; i++) {
		string *word = path->words[i];
		result[i] = new char[word->length() + 1];
		strcpy_s(result[i], word->length() + 1, word->data());
	}
	return wordCount;
}

/* Convert an English word to lower case.
   Throws exception if str is empty or contains non-English character.*/
string *ToLowerCase(string str) {
	string *r = new string();
	if (str.length() == 0) {
		throw exception("Empty string.");
	}
	for (unsigned int i = 0; i < str.length(); i++) {
		if (isalpha(str[i])) {
			r->append(1, tolower(str[i]));
		}
		else {
			throw exception("Contains non-English character");
		}
	}
	return r;
}

Edge::Edge(std::string * word, Node * to_node) {
	this->word = word;
	this->weight = -int(this->word->length());
	this->to_node = to_node;
	this->visited = false;
}

Node::Node(char letter, int node_idx) {
	this->letter = letter;
	this->node_idx = node_idx;
}

Path::Path(int capacity) {
	words.reserve(capacity);
}

int Path::CharLength() {
	int len = 0;
	for (unsigned int i = 0; i < words.size(); i++) {
		len += words[i]->length();
	}
	return len;
}

int Path::WordCount() {
	return words.size();
}

int Path::Length(bool isWeighted) {
	return isWeighted ? CharLength() : WordCount();
}

WordGraph::WordGraph(char *words[], int len) {
	this->num_edges = len;
	for (int i = 0; i < 26; i++) {
		nodes[i] = new Node('a' + i, i);
	}
	for (int i = 0; i < len; i++) {
		string *word = ToLowerCase(words[i]);
		for (int j = 0; j < i; j++) {
			if (words[j] == *word) {
				throw exception("Duplicate words.");
			}
		}
		char start = (*word)[0];
		char end = (*word)[(*word).length() - 1];
		nodes[start - 'a']->edges.push_back(new Edge(word, nodes[end - 'a']));
	}
	DetectCycle();
}

void WordGraph::DetectCycle() {
	isCyclic = false;

	for (int i = 0; i < 26 && !this->isCyclic; i++) {
		int status[26];
		for (int i = 0; i < 26; i++) {
			status[i] = NotExplored;
		}
		DFS(i, status);
	}
}

void WordGraph::DFS(int node_idx, int status[]) {
	status[node_idx] = BeingExplored;
	for (unsigned int i = 0; i < nodes[node_idx]->edges.size(); i++) {
		int adj_idx = nodes[node_idx]->edges[i]->to_node->node_idx;
		if (status[adj_idx] == NotExplored) {
			DFS(adj_idx, status);
		}
		// Words like "algebra" are not regarded as cyclic.
		else if (status[adj_idx] == BeingExplored && adj_idx != node_idx) {
			this->isCyclic = true;
			return;
		}
	}
	status[node_idx] = FullyExplored;
}

Node *WordGraph::GetNode(char letter) {
	return nodes[letter - 'a'];
}

void WordGraph::LongestPathBetweenDFS(char start, char end, vector<Edge*>& edgeStack, int &maxLen, Path **longestPath, bool isWeighted)
{
	Node *startNode = GetNode(start);
	for (unsigned int i = 0; i < startNode->edges.size(); i++) {
		Edge *edge = startNode->edges[i];
		if (!edge->visited) {
			edge->visited = true;
			edgeStack.push_back(edge);
			LongestPathBetweenDFS(edge->to_node->letter, end, edgeStack, maxLen, longestPath, isWeighted);
			edge->visited = false;
			edgeStack.pop_back();
		}
	}

	if (start == end) {
		if (edgeStack.size() < 2) {
			return;
		}
		Path *path = new Path(this->num_edges);
		for (unsigned int i = 0; i < edgeStack.size(); i++) {
			path->words.push_back(edgeStack[i]->word);
		}
		if (*longestPath == nullptr) {
			*longestPath = path;
			maxLen = path->Length(isWeighted);
		}
		else {
			if (path->Length(isWeighted) > maxLen) {
				delete *longestPath;
				maxLen = path->Length(isWeighted);
				*longestPath = path;
			}
			else {
				delete path;
			}
		}
	}
}

/* Returns a longest path which begins with `start` and ends with `end`.
   Returns null if there is no path between start and end.
   The length of a path is the number of characters along the path
   if isWeighted is set true, otherwise it will be the number of words. */
Path *WordGraph::LongestPathBetween(char start, char end, bool isWeighted) {
	vector<Edge*> edgeStack;
	edgeStack.reserve(this->num_edges);
	int maxLen = 0;
	Path *longestPath = nullptr;
	LongestPathBetweenDFS(start, end, edgeStack, maxLen, &longestPath, isWeighted);
	return longestPath;
}

void WordGraph::LongestPathFromDFS(char start, vector<Edge*>& edgeStack, int &maxLen, Path **longestPath, bool isWeighted)
{
	Node *startNode = GetNode(start);
	for (unsigned int i = 0; i < startNode->edges.size(); i++) {
		Edge *edge = startNode->edges[i];
		if (!edge->visited) {
			edge->visited = true;
			edgeStack.push_back(edge);
			LongestPathFromDFS(edge->to_node->letter, edgeStack, maxLen, longestPath, isWeighted);
			edge->visited = false;
			edgeStack.pop_back();
		}
	}

	if (edgeStack.size() < 2) {
		return;
	}
	Path *path = new Path(this->num_edges);
	for (unsigned int i = 0; i < edgeStack.size(); i++) {
		path->words.push_back(edgeStack[i]->word);
	}
	if (*longestPath == nullptr) {
		*longestPath = path;
		maxLen = path->Length(isWeighted);
	}
	else {
		if (path->Length(isWeighted) > maxLen) {
			delete *longestPath;
			maxLen = path->Length(isWeighted);
			*longestPath = path;
		}
		else {
			delete path;
		}
	}
}

/* Returns a longest path which begins with letter `start`.
   Returns null if there is no path beginning with `start`.
   The length of a path is the number of characters along the path
   if isWeighted is set true, otherwise it will be the number of words.*/
Path *WordGraph::LongestPathFrom(char start, bool isWeighted) {
	vector<Edge*> edgeStack;
	edgeStack.reserve(this->num_edges);
	int maxLen = 0;
	Path *longestPath = nullptr;
	LongestPathFromDFS(start, edgeStack, maxLen, &longestPath, isWeighted);
	return longestPath;
}

/* Returns a longest path which ends with `end`. Returns null if no path is found.
   The length of a path is the number of characters along the path
   if isWeighted is set true, otherwise it will be the number of words.*/
Path * WordGraph::LongestPathTo(char end, bool isWeighted)
{
	int maxLength = 0;
	Path *longestPath = nullptr;
	for (char c = 'a'; c <= 'z'; c++) {
		Path *path = LongestPathBetween(c, end, isWeighted);
		if (path == nullptr) {
			continue;
		}
		if (path->Length(isWeighted) > maxLength) {
			if (longestPath != nullptr) {
				delete longestPath;
			}
			maxLength = path->Length(isWeighted);
			longestPath = path;
		}
		else {
			delete path;
		}
	}
	return longestPath;
}

/* Returns a longest path in this graph. Returns null if no path is found.
   The length of a path is the number of characters along the path
   if isWeighted is set true, otherwise it will be the number of words.*/
Path * WordGraph::LongestPath(bool isWeighted)
{
	int maxLength = 0;
	Path *longestPath = nullptr;

	for (char start = 'a'; start <= 'z'; start++) {
		Path *path = LongestPathFrom(start, isWeighted);
		if (path == nullptr) {
			continue;
		}
		if (path->Length(isWeighted) > maxLength) {
			if (longestPath != nullptr) {
				delete longestPath;
			}
			maxLength = path->Length(isWeighted);
			longestPath = path;
		}
		else {
			delete path;
		}
	}

	return longestPath;
}

bool WordGraph::IsCyclic() {
	return this->isCyclic;
}
