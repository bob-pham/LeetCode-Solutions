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

bool compare(const ListNode * a, const ListNode * b) {
    if (b == nullptr) {
        return true;
    } else if (a == nullptr) {
        return false;
    } else {
        return a->val > b->val;
    }

}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * head = nullptr;
        ListNode * curr = nullptr;

        if (lists.size() == 0) {
            return head;
        }

        std::make_heap(lists.begin(), lists.end(), compare);
        std::pop_heap(lists.begin(), lists.end(), compare);

        while (lists.size() > 0 && lists.back() == nullptr) {
            lists.pop_back();
            if (lists.size() > 0) {
                std::pop_heap(lists.begin(), lists.end(), compare);
            }
        }

        if (lists.size() > 0) {
            std::pop_heap(lists.begin(), lists.end(), compare);
            head = lists.back();
            curr = head;
            ListNode * temp = head;
            printf("%d\n", temp->val);
            temp = temp->next;

            if (temp != nullptr) {
                lists.push_back(temp);
                std::push_heap(lists.begin(), lists.end(), compare);
            }
        }

        if (head != nullptr) {
            head->next = nullptr;
        }

        while (lists.size() > 0) {
            std::pop_heap(lists.begin(), lists.end(), compare);
            ListNode * temp = lists.back();
            lists.pop_back();

            if (temp == nullptr) {
                continue;
            }

            printf("%d\n", temp->val);

            curr->next = temp;
            curr = temp;
            curr->next = nullptr;

            temp = temp->next;

            if (temp != nullptr) {
                lists.push_back(temp);
                std::push_heap(lists.begin(), lists.end(), compare);
            }
        }

        return head;
    }
};
// @leet end
