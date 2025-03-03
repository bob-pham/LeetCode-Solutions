// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	int carry = 0;
	struct ListNode* head = NULL;
	struct ListNode * prev = NULL;

	while (l1 != NULL || l2 != NULL || carry != 0) {
		struct ListNode * curr = malloc(sizeof(struct ListNode));
		int v1 = 0;
		int v2 = 0;

		if (l1 != NULL) {
			v1 = l1->val;
			l1 = l1->next;
		}

		if (l2 != NULL) {
			v2 = l2->val;
			l2 = l2->next;
		}

		int val = v1 + v2 + carry;
		carry = val / 10;
		curr->val = val % 10;

		if (prev != NULL) {
			prev->next = curr;
		} else {
			head = curr;
		}
		prev = curr;
	}

	if (prev != NULL) {
		prev->next = NULL;
	}

	return head;
}
// @leet end
