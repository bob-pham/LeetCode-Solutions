// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
static bool listContains(int * nums, int numsSize, int k) {
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] == k) {
			return true;
		}
	}
	return false;
}

struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
	struct ListNode * curr = head;
	struct ListNode * prev = NULL;

	while (curr != NULL) {
		while (curr != NULL && listContains(nums, numsSize, curr->val)) {
			curr = curr->next;
		}
		if (prev == NULL) {
			head = curr;
			prev = curr;
		} else {
			prev->next = curr;
			prev = curr;
		}
		if (curr != NULL) {
			curr = curr->next;
		}
	}

	return head;
    
}
// @leet end
