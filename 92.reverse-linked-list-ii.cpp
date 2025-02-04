// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode * left0 = nullptr;
        ListNode * left1 = nullptr;
        ListNode * right0 = nullptr;
        ListNode * right1 = nullptr;
        ListNode * curr = head;

        if (left == right) {
            return head;
        }

        for (int i = 1; i <= right; i++) {
            if (i < left) {
                left0 = curr;
            } else if (i == left) {
                left1 = curr;
            } else if (i <= right) {
                right0 = curr;
            }
            curr = curr->next;
        }

        right1 = right0->next;
        ListNode * prev = nullptr;
        curr = left1;

        while (curr != nullptr && curr != right1) {
            ListNode * nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
        }

        left1->next = right1;
        if (left0 == nullptr) {
            return right0;

        } else {
            left0->next = right0;
        }

        return head;
    }
};
// @leet end
