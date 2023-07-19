#include "doctest.h"
#include "tree.h"
#include <iostream>

using namespace std;

inline int Sgn(int x) {
  if (x > 0) return 1;
  else if (x == 0)
    return 0;
  else
    return -1;
}

Node *CommonAncestorBST(Node *node, int n1, int n2) {
  if (!node) return node;
  int dl = n1 - node->data;
  int dr = n2 - node->data;
  int dsum = Sgn(dl) + Sgn(dr);
  switch (dsum) {
    case 2:
      // both on right
      return CommonAncestorBST(node->right, n1, n2);
    case -2:
      // both on left
      return CommonAncestorBST(node->left, n1, n2);
    case 0:
    case 1:
    case -1:
      // one on left and one on right
      // OR one on right and one on node
      // OR one on left and one on node
      return node;
  }
}

TEST_CASE("Tree" * doctest::description("common ancestor of BST")) {
  Node *bst = BuildTree("5 3 8 1 4 6 9 N 2 N N N 7 N N N N N N");
  cout << CommonAncestorBST(bst, 4, 2)->data;
}