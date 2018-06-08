#include "stdafx.h"
#include <iostream>
#include <queue>
#include <ctime>
#include <iomanip>
#define ELEMENTS 15
#define MAX_NUM 99
#define MIN_NUM -99

using namespace std;

struct Node {
	float data;
	Node *left, *right;
};

void print_tree(Node*, int);
Node* Creat_Node(int);
Node* Creat_tree();
void Add(Node**, Node*);
void Delete_element(Node**, int);
void Clear_tree(Node **);
void problem();
float max_in_tree(Node*);
float min_in_tree(Node*);