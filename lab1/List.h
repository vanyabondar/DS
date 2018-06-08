
struct Node {
	int x;
	string s;
};

struct List {
	Node Data;
	List *Next;
};

void Add(List ** L, int x, string s);
void Write(List * L);
void Clear(List * L);
void Pasting(List **L1, List ** L2); #pragma once
