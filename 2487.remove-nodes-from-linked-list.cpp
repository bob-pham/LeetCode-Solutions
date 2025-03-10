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
    ListNode* removeNodes(ListNode* head) {
        int right_max = this->removeNodeHelper(head->next, head);
        if (right_max > head->val) {
            return head->next;
        }
        return head;
    }

    int removeNodeHelper(ListNode * curr, ListNode * prev) {
        if (curr == nullptr) {
            return -1;
        }

        int right_max = removeNodeHelper(curr->next, curr);

        if (right_max > curr->val) {
            prev->next = curr->next;
            return right_max;
        }
        return curr->val;
    }
};
// @leet end
