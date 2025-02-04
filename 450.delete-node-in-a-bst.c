// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
	if (root == NULL) {
		return root;
	}

	if (root->val == key) {
		struct TreeNode * prev;
		struct TreeNode * curr;
		if (root->left == NULL && root->right == NULL) {
			return NULL;
		}

		if (root->left == NULL) {
			prev = root->right;
			if (prev->left == NULL) {
				prev->left = root->left;
				return prev;
			}

			curr = prev->left;
			while (curr->left != NULL) {
				prev = curr;
				curr = curr->left;
			}

			prev->left = curr->right;
			curr->left = root->left;
			curr->right = root->right;
			return curr;
		} else {
			prev = root->left;
			if (prev->right == NULL) {
				prev->right = root->right;
				return prev;
			}

			curr = prev->right;
			while (curr->right != NULL) {
				prev = curr;
				curr = curr->right;
			}

			prev->right = curr->left;
			curr->left = root->left;
			curr->right = root->right;
			return curr;

		}
	} else if (root->val > key) {
		root->left = deleteNode(root->left, key);
	} else {
		root->right = deleteNode(root->right, key);
	}

	return root;
}
// @leet end
