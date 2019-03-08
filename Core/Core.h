#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <string.h>

class Core {
public:
	static int gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
	static int gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
private:
	static int gen_chain(char* words[], int len, char* result[], char head, char tail, bool enable_loop, bool isWeighted);
};

struct Node;

struct Edge {
	std::string *word;
	int weight;
	Node *to_node;
	bool visited;
	Edge(std::string * word, Node * to_node);
};

struct Node {
	char letter;
	std::vector<Edge *> edges;
	int node_idx;
	Node(char letter, int node_idx);
};

class Path {
public:
	char start;
	char end;
	std::vector<std::string *> words;

	Path(char start, char end);
	std::string *ToString();
	int WordCount();
	int CharLength();
	int Length(bool isWeighted);
};

class WordGraph {
private:
	enum NodeStatus { NotExplored, BeingExplored, FullyExplored };

	bool isCyclic;
	Node *nodes[26]; // array

	Node *GetNode(char letter);
	void DetectCycle();
	void DFS(int node_idx, int visited[]);

	void DFSPathFind(char start, char end, std::vector<Edge*>& edgeStack, std::vector<Path*>& paths);
	std::vector<Path*>* AllPathsBetween(char start, char end);

public:
	WordGraph(char *words[], int len);
	bool IsCyclic();
	Path *LongestPathFrom(char start, bool isWeighted);
	Path *LongestPathBetween(char start, char end, bool isWeighted);
	Path *LongestPathTo(char end, bool isWeighted);
	Path *LongestPath(bool isWeighted);
	void print(); // debug;
};

