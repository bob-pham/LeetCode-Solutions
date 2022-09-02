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
        vector<int> nodes;
        ListNode* curr = head;
        
        while(curr) {
            nodes.push_back(curr->val);
            curr = curr->next;
        } 
        
        for (int i = 0, j = nodes.size() - 1; i < j; i++, j--) {
            if (nodes[i] != nodes[j])
                return false;
        }
        
        return true;
    }
};