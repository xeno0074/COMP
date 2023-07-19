#include "doctest.h"
#include "tree.h"
#include <iostream>
#include <queue>

using namespace std;

int maxPathSum = INT_MIN;

int MaxHeightSum(TreeNode *node) {
  if (!node) return 0;

  int lsum = MaxHeightSum(node->left);
  int rsum = MaxHeightSum(node->right);

  maxPathSum = max(maxPathSum, lsum + rsum + node->val);

  return node->val + (lsum, rsum);
}

int MaxPathSum(TreeNode *root) {
  MaxHeightSum(root);
  int res = maxPathSum;
  maxPathSum = INT_MIN;
  return res;
}

TEST_CASE("Tree" * doctest::description("max_path_sum")) {
  auto tree = BuildTree("-10 2 3 4 -1 -4 4");
  inot(tree);
  cout << endl;
  cout << MaxPathSum(tree);
}