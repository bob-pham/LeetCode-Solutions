// @leet start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node * curr = head;
        
        while (curr != nullptr) {
            Node * child_head = flatten(curr->child);
            Node * temp_next = curr->next;
            Node * child_tail = child_head;
            
            while (child_tail != nullptr && child_tail->next != nullptr) {
                child_tail = child_tail->next;
            }

            if (child_head != nullptr) {
                curr->next = child_head;
                child_head->prev = curr;
                child_tail->next = temp_next;
                if (temp_next != nullptr) {
                    temp_next->prev = child_tail;
                }
            }

            curr->child = nullptr;
            curr = temp_next;
        }

        return head;
    }
};
// @leet end
