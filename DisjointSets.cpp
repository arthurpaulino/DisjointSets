#include <cstdlib>
#include <cstdio>
#include "DisjointSets.h"

void DisjointSets::reset() {
	for (int i = 0; i < n; i++) {
		nodes[i].color = i;
		nodes[i].next = NULL;
		colors[i].size = 1;
		colors[i].first = &nodes[i];
		colors[i].last = &nodes[i];
	}
}

DisjointSets::DisjointSets(int n) {
	this->n = n;
	
	colors = (Color*)malloc(n*sizeof(Color));
	nodes = (Node*)malloc(n*sizeof(Node));
	for (int i = 0; i < n; i++) nodes[i].label = i;
	
	reset();
}

bool DisjointSets::belongToSameSet(int a, int b) {
	return nodes[a].color == nodes[b].color;
}

void DisjointSets::unify_(int bigger, int smaller) {
	Color *biggerColor = &colors[nodes[bigger].color];
	Color *smallerColor = &colors[nodes[smaller].color];

	Node* iterNode = smallerColor->first;
	while (iterNode != NULL) {
		iterNode->color = bigger;
		iterNode = iterNode->next;
	}
	
	biggerColor->last->next = smallerColor->first;
	biggerColor->last = smallerColor->last;
	
	smallerColor->first = NULL;
	smallerColor->last = NULL;
	
	biggerColor->size += smallerColor->size;
	smallerColor->size = 0;
}

void DisjointSets::unify(int a, int b) {
	if (belongToSameSet(a,b)) return;
	if (colors[a].size > colors[b].size) unify_(a,b);
	else unify_(b,a);
}

void DisjointSets::printSets() {
	for (int i = 0; i < n; i++) {
		Color *color = &colors[i];
		if (color->size != 0) {
			printf("{");
			Node *iterNode = color->first;
			while (iterNode != NULL) {
				printf("%d",iterNode->label);
				iterNode = iterNode->next;
				if (iterNode != NULL) printf(",");
			}
			printf("} ");
		}
	}
	printf("\n");
}
