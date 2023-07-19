#include "doctest.h"
#include "tree.h"

namespace tree_swap_fix_bst {
  vector<Node *> v;

  inline void Swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
  }

  void Inot(Node *node) {
    if (!node) return;
    Inot(node->left);
    v.push_back(node);
    Inot(node->right);
  }

  Node *FixBST(Node *node) {
    // inorder to a vector v
    Inot(node);

    // find critical points from v and store in pair p
    int length = v.size();
    pair<Node *, Node *> p;
    for (int i = 0; i < length - 1; i++) {
      if (v[i]->data > v[i + 1]->data) {
        p.first = v[i];
        break;
      }
    }
    for (int j = length - 1; j > 0; j--) {
      if (v[j]->data < v[j - 1]->data) {
        p.second = v[j];
        break;
      }
    }

    // swap the values in the Nodes pointed by p
    Swap(&p.first->data, &p.second->data);

    v.clear();
    return node;
  }

  TEST_CASE("swap_fix_bst") {
    Node *tree = BuildTree("5 3 8 1 2 6 9 N 4 N N N 7 N N N N N N");
    inot(FixBST(tree));
  }
}// namespace tree_swap_fix_bst