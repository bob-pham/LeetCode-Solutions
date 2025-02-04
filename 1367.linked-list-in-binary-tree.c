// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static bool isSubPathHelper(struct ListNode* head, struct TreeNode* root, bool found);

bool isSubPath(struct ListNode* head, struct TreeNode* root) {
	return isSubPathHelper(head, root, false);
}

static bool isSubPathHelper(struct ListNode* head, struct TreeNode* root, bool found) {
	if (head == NULL) {
		return true;
	}

	if (root == NULL) {
		return false;
	}

	if (head->val == root->val) {
		if (isSubPathHelper(head->next, root->left, true) ||
		    isSubPathHelper(head->next, root->right, true)) {
			return true;
		}
	}
	if (found) {
		return false;
	}
	return (isSubPathHelper(head, root->left, false) ||
		isSubPathHelper(head, root->right, false));
}

// @leet end
