#include "doctest.h"
#include "tree.h"
#include <iostream>

using namespace std;

vector<vector<Node *>> forest;

vector<Node *> FetchSubTrees(int n, int s) {
  vector<Node *> row;
  if (!n) {
    row.push_back(NULL);
    return row;
  }
  for (Node *root: forest[n]) { row.push_back(DuplicateTree(root, s)); }
  return row;
}

vector<Node *> GenUniqueBSTs(int n) {
  forest.resize(n + 1);
  vector<Node *> row;

  //  insert item for forest[0]
  row.push_back(NULL);
  forest[0] = row;
  row.clear();

  for (int index = 1; index <= n; index++) {
    for (int rootNum = 1; rootNum <= index; rootNum++) {
      vector<Node *> leftSubTrees = FetchSubTrees(rootNum - 1, 0);
      vector<Node *> rightSubTrees = FetchSubTrees(index - rootNum, rootNum);
      for (Node *lNode: leftSubTrees) {
        for (Node *rNode: rightSubTrees) {
          Node *node = new Node(rootNum);
          node->left = lNode;
          node->right = rNode;
          forest[index].push_back(node);
        }
      }
    }
  }
  return FetchSubTrees(n, 0);
}

TEST_CASE("Tree" * doctest::description("unique BSTs")) {
  auto t = GenUniqueBSTs(3);
  for (auto x: t) cout << ToString(x) << endl;
}
