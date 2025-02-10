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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode * left = list1;
        ListNode * right = nullptr;

        for (int i = 0; i < a - 1; i++) {
            left = left->next;
        }

        right = left;

        for (int i = 0; i < (b - a) + 2; i++) {
            right = right->next;
        }

        left->next = list2;
        
        while (left->next != nullptr) {
            left = left->next;
        }

        left->next = right;

        return list1;
    }
};
// @leet end
