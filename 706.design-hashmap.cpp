// @leet start
class Node {
public:
    int key;
    int val;
    Node * next;
    Node * prev;
    Node(int key, int value) {
        this->key = key;
        this->val = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class MyHashMap {
private:
    Node ** map;

    Node * getKeyNode(int key) {
        int hash = key % 4096;
        Node * curr = this->map[hash];
        while(curr != nullptr && curr->key != key) {
            curr = curr->next;
        }

        return curr;
    }

public:
    MyHashMap() {
        this->map = new Node*[4096]();
    }
    
    void put(int key, int value) {
        Node * curr = this->getKeyNode(key);
        if (curr != nullptr) {
            curr->val = value;
        } else {
            int hash = key % 4096;
            curr = new Node(key, value);
            curr->next = this->map[hash];
            if (this->map[hash]) {
                this->map[hash]->prev = curr;
            }
            this->map[hash] = curr;
        }
    }
    
    int get(int key) {
        Node * curr = this->getKeyNode(key);
        if (curr != nullptr) {
            return curr->val;
        }
        return -1;
    }
    
    void remove(int key) {
        Node * curr = this->getKeyNode(key);
        if (curr != nullptr) {
            int hash = key % 4096;
            if (this->map[hash] == curr) {
                this->map[hash] = curr->next;
            }
            if (curr->prev != nullptr) {
                curr->prev->next  = curr->next;
            }
            if (curr->next != nullptr) {
                curr->next->prev  = curr->prev;
            }

            delete curr;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @leet end
