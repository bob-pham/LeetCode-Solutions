// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    return hasPathSumHelper(root, targetSum, 0);
  }

  bool hasPathSumHelper(TreeNode *root, int targetSum, int currentSum) {
    if (root == nullptr) {
      return false;
    }

    currentSum += root->val;

    if (root->left == nullptr && root->right == nullptr &&
        currentSum == targetSum) {
      return true;
    }

    return hasPathSumHelper(root->left, targetSum, currentSum) ||
           hasPathSumHelper(root->right, targetSum, currentSum);
  }
};
// @leet end
