#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <string.h>

#define NUM_NODES 26

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
	bool visited; // used in LongestPathFromDFS()
	Edge(std::string * word, Node * to_node);
};

struct Node {
	char letter;
	std::vector<Edge *> edges;
	int node_idx;

	// for topo sort
	int indegree;

	// path finding, initalize these variables before using.
	int dist;
	Edge *edgeToThis;
	Node *pred;
	bool selfLoop;
	Edge *selfLoopEdge;

	Node(char letter, int node_idx);
};

class Path {
public:
	std::vector<std::string *> words;
	Path(int capacity);
	int WordCount();
	int CharLength();
	int Length(bool isWeighted);
};

class WordGraph {
private:
	enum NodeStatus { NotExplored, BeingExplored, FullyExplored };

	bool isCyclic;
	bool isWeightedGraph;
	Node *nodes[NUM_NODES]; // array
	int num_edges;

	Node *GetNode(char letter);
	void DetectCycle();
	void DFS(int node_idx, int visited[]);

	void TopoSort(std::vector<Node *> &result);
	void SetWeight(bool isWeighted);

	void MarkLongestPathFromAcyclic(char start);

	Path * ConstructPath(Node * node);

	void LongestPathBetweenDFS(char start, char end, std::vector<Edge*>& edgeStack, int &maxLen, Path **longestPath, bool isWeighted);
	Path * LongestPathBetweenCyclicOrAcyclic(char start, char end, bool isWeighted);
	void LongestPathFromDFS(char start, std::vector<Edge*>& edgeStack, int & maxLen, Path ** longestPath, bool isWeighted);
	Path * LongestPathFromCyclicOrAcyclic(char start, bool isWeighted);

	Path * LongestPathBetweenAcyclic(char start, char end, bool isWeighted);
	Path * LongestPathFromAcyclic(char start, bool isWeighted);

public:
	WordGraph(char *words[], int len);
	bool IsCyclic();
	Path *LongestPathFrom(char start, bool isWeighted);
	Path *LongestPathBetween(char start, char end, bool isWeighted);
	Path *LongestPathTo(char end, bool isWeighted);
	Path *LongestPath(bool isWeighted);
};

