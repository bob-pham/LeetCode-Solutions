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
    bool hasCycle(ListNode *head) {
        ListNode * fastNode = head;
        ListNode * slowNode = head;
        bool turn = false;

        while (fastNode != nullptr) {
            fastNode = fastNode->next;
            if (turn) {
                slowNode = slowNode->next;
            }
            turn = !turn;

            if (slowNode == fastNode) {
                return true;
            }
        }

        return false;
        
       
    }
};
// @leet end
