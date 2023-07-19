#include "doctest.h"
#include "tree.h"
#include <iostream>

using namespace std;

vector<int> v;

void Inot(Node *node) {
  if (!node) return;
  Inot(node->left);
  v.push_back(node->data);
  Inot(node->right);
}

bool IsBST(Node *node) {
  Inot(node);
  int max = INT_MIN;
  for (auto x: v) {
    if (x <= max) {
      v.clear();
      return false;
    }
    max = x;
  }
  v.clear();
  return true;
}

TEST_CASE("Tree" * doctest::description("BST verification")) {
  Node *tree = BuildTree("1 1 1 1 1 N 1 1 1 1 1");
  cout << IsBST(tree);
}