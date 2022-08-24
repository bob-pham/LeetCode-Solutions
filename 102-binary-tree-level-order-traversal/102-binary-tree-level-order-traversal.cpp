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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode*> path;
        vector<int> curr;
        vector<vector<int>> result;
        int level1 = 1;
        int level2 = 0;
        bool one = true;
        bool two = false;    
        
        if (!root) {
            return result;
        }
        
        path.push(root);
        
        while (!path.empty()) {
            TreeNode* temp = path.front();
            path.pop();
            curr.push_back(temp->val);
            
            if (one) {
                if (!--level1) {
                    two = true;
                    one = false;
                    result.push_back(curr);
                    curr = vector<int>();
                }
                if (temp->left) {
                    level2++;
                    path.push(temp->left);
                }
                if (temp->right) {
                    level2++;
                    path.push(temp->right);
                }
            } else if (two) {
                if (!--level2) {
                    two = false;
                    one = true;
                    result.push_back(curr);
                    curr = vector<int>();
                }
                if (temp->left) {
                    level1++;
                    path.push(temp->left);
                }
                if (temp->right) {
                    level1++;
                    path.push(temp->right);
                }
            }         
            
        }
        
        return result;
    }
};