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
    ListNode* middleNode(ListNode* head) {
        
        ListNode* curr = head;
        int length = 0;
        
        while (curr) {
            curr = curr->next;
            length++;
        }
        
        length = (length / 2) + 1;
        curr = head;
        
        while (--length > 0) {
            curr = curr->next;
        }
        
        return curr;
        
    }
};