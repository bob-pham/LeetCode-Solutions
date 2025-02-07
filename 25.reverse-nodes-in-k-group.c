// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverse(struct ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	struct ListNode * prev = head;
	struct ListNode * curr = head->next;
	head->next = NULL;

	while (curr != NULL) {
		struct ListNode * temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}

	return prev;
}

struct ListNode * splitKGroup(struct ListNode* head, int k) {
	struct ListNode * curr = head;
	int idx = 0; 

	while (curr != NULL && idx < k - 1) {
		curr = curr->next;
		idx++;
	}

	if (curr == NULL || idx < k - 1) {
		return NULL;
	}

	return curr;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
	struct ListNode * prev = NULL;
	struct ListNode * curr = head;

	while (curr != NULL) {
		struct ListNode * tail = splitKGroup(curr, k);

		if (tail == NULL) {
			if (prev == NULL) {
				return head;
			}
			prev->next = curr;
			return head;
		}

		struct ListNode * next = tail->next;
		tail->next = NULL;
		if (prev == NULL) {
			head = reverse(curr);
		} else {
			prev->next = reverse(curr);
		}
		prev = curr;
		curr = next;
	}
	return head;
}
// @leet end
