// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> visited;

        while(head != nullptr) {
            visited.insert(head);
            if (visited.find(head->next) != visited.end()) {
                return head->next;
            }
            head = head->next;

        }
        return nullptr;
    }
};
// @leet end
