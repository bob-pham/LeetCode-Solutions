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
#include <unordered_set>
class Solution {
public:
    int maxPathSum(TreeNode* root) {
       return maxPathSumHelper(root, unordered_set<int>(), 0);
    }

    int maxPathSumHelper(TreeNode * curr, unordered_set<int> visited, int curr_sum) {
        if (curr == nullptr) {
            return curr_sum;
        }
        int val = curr->val;

        if (visited.find(curr->val) == visited.end()) {
            visited.insert(val);
            return max(maxPathSumHelper(curr->left, visited, curr_sum + val),
                        maxPathSumHelper(curr->right, visited, curr_sum + val));
        } else {
            return max({maxPathSumHelper(curr->left, unordered_set<int>(), 0),
                        maxPathSumHelper(curr->right, unordered_set<int>(), 0), curr_sum});
        }
    }
};
// @leet end
