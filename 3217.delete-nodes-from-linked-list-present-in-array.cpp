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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
 	ListNode * curr = head;
	ListNode * prev = nullptr;
        unordered_set<int> nums_set;

        for (int i : nums) {
            nums_set.insert(i);
        }

	while (curr != nullptr) {
		while (curr != nullptr && (nums_set.find(curr->val) != nums_set.end())) {
			curr = curr->next;
		}
		if (prev == nullptr) {
			head = curr;
			prev = curr;
		} else {
			prev->next = curr;
			prev = curr;
		}
		if (curr != nullptr) {
			curr = curr->next;
		}
	}

	return head;       
    }
};
// @leet end
