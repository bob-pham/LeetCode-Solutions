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
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;

        ListNode * curr = head;
        while (curr != nullptr) {
            nodes.push_back(curr);
            curr = curr->next;
        }

        if (nodes.size() <= 2) {
            return;
        }

        int s = nodes.size();

        for (int i = 1; i < (s % 2 == 0 ? s - 1 : s - 2); i++) {
            ListNode * temp = nodes[i];
            nodes[i] = nodes[s - 1];
            nodes[s - 1] = temp;
        }

        for (int i = 0; i < (s - 1); i++) {
            nodes[i]->next = nodes[i + 1];
            nodes[i + 1]->next = nullptr;
        }
    }
};
// @leet end
