// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	struct ListNode * curr = head;
	struct ListNode * prev = NULL;
	struct ListNode * next = head->next->next;
	head = head->next;
	head->next = curr;
	curr->next = next;
	prev = curr;
	curr = next;

	while (curr != NULL && curr->next != NULL) {
		next = curr->next->next;
		prev->next = curr->next;
		curr->next->next = curr;
		curr->next = next;
		prev = curr;
		curr = next;
	}

	return head;
    
}
// @leet end
