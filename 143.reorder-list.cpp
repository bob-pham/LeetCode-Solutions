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
        deque<ListNode*> nodes;

        ListNode * curr = head;
        while (curr != nullptr) {
            nodes.push_back(curr);
            curr = curr->next;
        }

        if (nodes.size() <= 2) {
            return;
        }

        ListNode * prev = nullptr;
        while (nodes.size() > 1) {
            ListNode * front = nodes.front();
            ListNode * back = nodes.back();
            nodes.pop_front();
            nodes.pop_back();
            front->next = back;

            if (prev != nullptr) {
                prev->next = front;
            }
            prev = back;
            back->next = nullptr;
        }

        if (nodes.size() == 1) {
            ListNode * front = nodes.front();
            prev->next = front;
            nodes.pop_back();
            front->next = nullptr;
        }
    }
};
// @leet end
