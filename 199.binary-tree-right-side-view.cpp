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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<pair<int, TreeNode*>> todo;
        int current_level = 0;
        TreeNode * prev = nullptr;

        todo.push(pair<int, TreeNode *>(0, root));

        while (todo.size() > 0) {
            pair<int, TreeNode*> curr = todo.front();
            todo.pop();

            if (curr.second == nullptr) {
                continue;
            }

            if (curr.first != current_level) {
                result.push_back(prev->val);
            }
            current_level = curr.first;
            prev = curr.second;


            todo.push(pair<int, TreeNode *>(curr.first + 1, curr.second->left));
            todo.push(pair<int, TreeNode *>(curr.first + 1, curr.second->right));
        }

        if (prev != nullptr) {
            result.push_back(prev->val);
        }

        return result;
    }
};
// @leet end
