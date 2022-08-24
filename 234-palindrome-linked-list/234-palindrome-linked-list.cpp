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
    bool isPalindrome(ListNode* head) {
        stack<int> backward; 
        queue<int> forward;
        ListNode* curr = head;
        
        while (curr) {
            backward.push(curr->val);
            forward.push(curr->val);
            curr = curr->next;
        }
                
        for (int i = 0; i < backward.size() / 2 + 1; i++) {
            if (forward.front() != backward.top()) {
                return false;
            }
            backward.pop();
            forward.pop();
        }
        
        return true;
    }
};