// @leet start

class FriendNode {
public:
    FriendNode * prev;
    FriendNode * next;
    int val;

    FriendNode(int val) {
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }

};

class Solution {
public:
    int findTheWinner(int n, int k) {

        if (n == 1) {
            return n;
        }

        FriendNode * head = new FriendNode(1);
        FriendNode * prev = head;

        for (int i = 2; i <= n; i++) {
            FriendNode * curr = new FriendNode(i);
            prev->next = curr;
            curr->prev = prev;
            prev = curr;
        }

        head->prev= prev;
        prev->next = head;

        while(head != nullptr && head->next != head && head->prev != head) {
            FriendNode * curr = head;

            for (int i = 0; i < k - 1; i++) {
                curr = curr->next;
            }
            head = curr->next;
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete(curr);
        }

        int result = head->val;
        delete head;
        return result;
    }
};
// @leet end
