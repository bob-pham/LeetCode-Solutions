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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * result = nullptr;
        ListNode * curr = nullptr;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr) {
            int v1 = l1 == nullptr ? 0 : l1->val;
            int v2 = l2 == nullptr ? 0 : l2->val;
            int ans = v1 + v2 + carry;
            carry = ans / 10;
            ans = ans % 10;
            
            ListNode * new_node = new ListNode(ans);

            if (result == nullptr) {
                result = new_node;
            } else {
                curr->next = new_node;
            }
            curr = new_node;

            l1 = l1 == nullptr ? l1 : l1->next;
            l2 = l2 == nullptr ? l2 : l2->next;
        }

        if (carry != 0) {
            ListNode * new_node = new ListNode(carry);
            curr->next = new_node;
            curr = new_node;
        }

        return result;
    }
};
// @leet end
