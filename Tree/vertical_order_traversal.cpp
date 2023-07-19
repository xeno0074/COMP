#include "doctest.h"
#include "tree.h"
#include <iostream>
#include <map>
#include <queue>

using namespace std;

map<int, vector<int>> m;

void Lot(Node *node) {
  queue<pair<Node *, int>> q;
  q.push(make_pair(node, 0));
  while (!q.empty()) {
    pair<Node *, int> p = q.front();
    q.pop();
    if (!p.first) continue;
    m[p.second].push_back(p.first->data);
    q.push(make_pair(p.first->left, p.second - 1));
    q.push(make_pair(p.first->right, p.second + 1));
  }
}

vector<int> VerticalOrder(Node *root) {
  vector<int> v;
  Lot(root);
  for (auto p: m) { v.insert(v.end(), p.second.begin(), p.second.end()); }
  m.clear();
  return v;
}

TEST_CASE("Tree" * doctest::description("vertical order traversal")) {
  Node *tree = BuildTree("1 2 3 4 6 N 7 N N N 5 8 9");
  vector<int> v = VerticalOrder(tree);
  for (auto x: v) cout << x << " ";
  cout << endl;
}