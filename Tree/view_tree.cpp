#include "doctest.h"
#include "tree.h"
#include <fstream>
using namespace std;

void print(Node *node, string fileName) {
  ofstream file;
  file.open(fileName, ios::out | ios::trunc);
  if (!file.is_open()) {
    // file cannot be made
  } else {
  }
}

TEST_CASE("view_tree") {
  Node *tree = BuildTree("1 2 3 4 6 N 7 N N N 5 8 9");
  print(tree, "tree.txt");
}