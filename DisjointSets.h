#ifndef H_DISJOINTSETS
#define H_DISJOINTSETS

#include <cstdlib>

class DisjointSets {

private:
	
	typedef struct Node {
		int label;
		int color;
		struct Node* next;
	}Node;
	
	typedef struct Color {
		int size;
		Node* first;
		Node* last;
	}Color;

	int n;
	Color* colors;
	Node* nodes;
	
	void unify_(int bigger,int smaller);
	
public:
	
	DisjointSets(int n);
	bool belongToSameSet(int a, int b);
	void unify(int a, int b);
	void printSets();
	void reset();
	
	virtual ~DisjointSets() {
		free(colors);
		free(nodes);
	}

};

#endif
