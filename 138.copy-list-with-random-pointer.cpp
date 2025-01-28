// @leet start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

#include <unordered_map>

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copies;

        Node* curr = head;
        Node* prev = nullptr;

        if (head == nullptr) {
            return head;
        }

        while (curr != nullptr) {
            Node * new_node = new Node(curr->val);
            copies[curr] = new_node;
            curr = curr->next;
            if (prev != nullptr) {
                prev->next = new_node;
            }
            prev = new_node;
        }

        curr = head;
        prev = copies[head];

        while (curr != nullptr) {
            if (copies[curr->random] != nullptr) {
                prev->random = copies[curr->random];
            }
            curr = curr->next;
            prev = prev->next;
        }

        return copies[head];
        
    }
};
// @leet end
