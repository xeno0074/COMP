#include "doctest.h"
#include "tree.h"
#include <iostream>

using namespace std;

int maxSum = INT_MIN;

int BranchSubSum(TreeNode *root) {
  if (!root) return 0;
  int l = BranchSubSum(root->left);
  int r = BranchSubSum(root->right);
  int s = l + r;

  l += root->val;
  r += root->val;
  s += root->val;

  maxSum = max(maxSum, l);
  maxSum = max(maxSum, r);
  maxSum = max(maxSum, s);

  if (l < 0 && r < 0) return 0;
  int ret = root->val;
  ret = max(ret, l);
  ret = max(ret, r);
  return ret;
}

TEST_CASE("Tree" * doctest::description("max connected path sum")) {
  auto tree = BuildTree("-10 2 3 4 -1 -4 2");
  BranchSubSum(tree);
  cout << maxSum;
}