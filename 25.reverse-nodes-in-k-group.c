// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* splitKGroup(struct ListNode* head, int k){
	struct ListNode *curr = head;
	int i = 0;

	while (curr != NULL && i < k - 1) {
		i++;
		if (curr->next == NULL) {
			return head;
		}
		curr = curr->next;
	}

	return curr;
}

struct ListNode* reverseSublist(struct ListNode* head) {
	struct ListNode* prev = NULL;
	struct ListNode* curr = head;

	while (curr != NULL) {
		struct ListNode * next= curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev == NULL ? head : prev;
}


struct ListNode* reverseKGroup(struct ListNode* head, int k) {
	struct ListNode* curr = head;
	struct ListNode* prev = NULL;
	struct ListNode* next = NULL;

	struct ListNode* tail = splitKGroup(curr, k);

	if (tail == curr) {
		return head;
	}
	next = tail->next;
	tail->next = NULL;

	head = reverseSublist(curr);
	prev = curr;
	curr = next;

	while (curr != NULL) {
		tail = splitKGroup(curr, k);
		next = tail->next;
		tail->next = NULL;

		prev->next = reverseSublist(curr);
		prev = curr;
		curr = next;
	}

	return head;
}
// @leet end
