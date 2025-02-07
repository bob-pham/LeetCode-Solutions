// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
	struct ListNode * left_node = head;
	struct ListNode * left_prev = NULL;
	struct ListNode * right_node = NULL;
	struct ListNode * right_next = NULL;

	if (left == right || head == NULL) {
		return head;
	}

	for (int i = 0; i < left - 1; i++) {
		left_prev = left_node;
		left_node = left_node->next;
	}

	right_node = left_node;
	for (int i = 0; i < right - left; i++) {
		right_node = right_node->next;
	}
	right_next = right_node->next;

	right_node->next = NULL;
	struct ListNode * prev = left_node;
	struct ListNode * curr = left_node->next;

	while (curr != NULL) {
		struct ListNode * temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}

	if (left_prev == NULL) {
		head = right_node;
	} else {
		left_prev->next = right_node;
	}
	left_node->next = right_next;

	return head;
}
// @leet end
