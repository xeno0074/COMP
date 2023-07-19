#pragma once
#include <string>
using namespace std;

struct Node {
  int data;
  int &val = data;
  Node *left, *right, *nextSibling;

  Node(int);
};

typedef Node TreeNode;

Node *BuildTree(string);
void preot(Node *);
void posot(Node *);
void inot(Node *);

string ToString(Node *);
Node *DuplicateTree(Node *, int = 0);