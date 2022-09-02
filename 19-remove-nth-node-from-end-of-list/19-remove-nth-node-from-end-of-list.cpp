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
        
        stack<ListNode*> stck;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        
        while (curr) {
            stck.push(curr);
            curr = curr->next;    
        }
        
        curr = head;
        
        while(--n) {
            prev = stck.top();
            stck.pop();
        }
        
        if (stck.empty()) {
            return nullptr;
        } else if (stck.top() == head) {
            return head->next;
        } else {
            stck.pop();
            stck.top()->next = prev;
            return head;
        }
        
    }
};