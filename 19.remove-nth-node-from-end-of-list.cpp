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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int size = 0;

        while (curr != nullptr) {
            curr = curr->next;
            size++;
        }

        curr = head;
        ListNode * prev = nullptr;
        for (int i = 0; i < (size - n); i++) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == head) {
            return curr->next;
        }

        prev->next = curr->next;
        return head;
        
    }
};
// @leet end
