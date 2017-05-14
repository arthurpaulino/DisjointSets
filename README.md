DisjointSets
============

An efficient, straightforward and user friendly implementation of the *disjoint sets* data structure written in C++. The constructor creates (given) *n* disjoint sets, with 1 element each. The elements are labeled from *0* to *n-1*.

It supports

* Instantiation

```cpp
DisjointSets *ds = new DisjointSets(n);
```

* Union of the sets that contain elements with labels *a* and *b*

```cpp
int a, b;
ds->unify(a, b);
```

* Union verification in *O(1)*

```cpp
bool belongToSameSet = ds->belongToSameSet(a, b);
```

* A print function

```cpp
fh->printSets();
```

* A reset function

```cpp
ds->reset();
