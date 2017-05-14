#include <cstdio>
#include "DisjointSets.h"

int main() {

	DisjointSets *ds = new DisjointSets(10);
	
	printf("Original sets:\n\t");
	ds->printSets();
	
	int a,b;
	
	a = 6; b = 9;
	ds->unify(a,b);
	printf("After unifying elements %d and %d:\n\t", a, b);
	ds->printSets();
	
	a = 1; b = 3;
	ds->unify(a,b);
	printf("After unifying elements %d and %d:\n\t", a, b);
	ds->printSets();
	
	a = 0; b = 3;
	ds->unify(a,b);
	printf("After unifying elements %d and %d:\n\t", a, b);
	ds->printSets();
	
	a = 2; b = 7;
	ds->unify(a,b);
	printf("After unifying elements %d and %d:\n\t", a, b);
	ds->printSets();
	
	a = 7; b = 1;
	ds->unify(a,b);
	printf("After unifying elements %d and %d:\n\t", a, b);
	ds->printSets();
	
	a = 4; b = 6;
	printf("Elements %d and %d belong to the same set: %s\n", a, b, ds->belongToSameSet(a,b)? "true" : "false");
	
	a = 7; b = 0;
	printf("Elements %d and %d belong to the same set: %s\n", a, b, ds->belongToSameSet(a,b)? "true" : "false");
	
	ds->reset();
	printf("After reseting the data structure:\n\t");
	ds->printSets();

	return 0;

}
