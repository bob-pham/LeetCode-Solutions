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

    ListNode* reverseLinkedList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode * prev = head;
        ListNode * curr = head->next;
        head->next = nullptr;

        while (curr != nullptr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

    ListNode * splitKNodes(ListNode* head, int k) {
        if (head == nullptr) {
            return 0;
        }

        ListNode * curr = head;
        int idx = 0;

        while (curr != nullptr && idx < k - 1) {
            curr = curr->next;
            idx++;
        }

        if (idx < k - 1) {
            return nullptr;
        }

        if (curr != nullptr) {
            return curr;
        }
        return nullptr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode * curr = head;
        ListNode * prev = nullptr;

        while (curr != nullptr) {
            ListNode * tail = splitKNodes(curr, k);
            if (tail == nullptr) {
                if (prev == nullptr) {
                    return head;
                }
                prev->next = curr;
                return head;
            }
            ListNode * next = tail->next;
            tail->next = nullptr;
            ListNode * temp = reverseLinkedList(curr);
            if (prev == nullptr) {
                head = temp;
            } else {
                prev->next = temp;
            }

            prev = curr;
            curr = next;
        }

        return head;
    }
};
// @leet end
