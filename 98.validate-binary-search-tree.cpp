// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <limits>

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        return isValidBSTHelper(root->left, std::numeric_limits<int64_t>::min(), root->val) &&
               isValidBSTHelper(root->right, root->val, std::numeric_limits<int64_t>::max());
    }

    bool isValidBSTHelper(TreeNode * node, int64_t min_val, int64_t max_val) {
        if (node == nullptr) {
            return true;
        }

        if (node->val <= min_val) {
            return false;
        }

        if (node->val >= max_val) {
            return false;
        }

        return isValidBSTHelper(node->left, min_val, node->val) &&
               isValidBSTHelper(node->right, node->val, max_val);
    }
};
// @leet end
