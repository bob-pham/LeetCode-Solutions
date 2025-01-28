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
#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        int curr_level = 1;
        vector<vector<int>> result;
        queue<pair<int, TreeNode*>> todo;
        vector<int> curr = vector<int>();

        if (root == nullptr) {
            return result;
        }

        result.push_back(vector<int>({root->val}));

        todo.push(pair<int, TreeNode *>(1, root->left));
        todo.push(pair<int, TreeNode *>(1, root->right));

        while (todo.size() > 0) {
            pair<int, TreeNode *> curr_pair = todo.front();
            todo.pop();

            if (curr_pair.first != curr_level) {
                curr_level = curr_pair.first;
                result.push_back(curr);
                curr = vector<int>();
            }

            if (curr_pair.second == nullptr) {
                continue;
            }

            curr.push_back(curr_pair.second->val);

            todo.push(pair<int, TreeNode*>(curr_pair.first + 1, curr_pair.second->left));
            todo.push(pair<int, TreeNode*>(curr_pair.first + 1, curr_pair.second->right));
        }

        return result;
    }
};
// @leet end
