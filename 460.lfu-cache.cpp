// @leet start

#include <unordered_map>

class LNode {
public:
    LNode * prev;
    LNode * next;
    int value;
    int key;
    int use;

    LNode(int key, int value) {
        this->key = key;
        this->value = value;
        this->prev = nullptr;
        this->next = nullptr;
        this->use = 0;
    }
};

class LFUCache {
private:
    unordered_map<int, LNode *> cache;
    LNode * head;
    LNode * tail;
    int capacity;
    int curr_capacity;
public:
    LFUCache(int capacity) {
        this->head = nullptr;
        this->tail = nullptr;
        this->capacity = capacity;
        this->curr_capacity = 0;
    }
    
    int get(int key) {
        
    }
    
    void put(int key, int value) {
        if (this->cache.find(key) != this->cache.end()) {
            LNode * node = new LNode(key, value);
            node->next = this->head;
            if (this->head == this->tail) {
                this->tail = node;
            }
            this->head = node;
            this->curr_capacity++;
            if (this->curr_capacity > this->capacity) {
                this->curr_capacity--;
                node = this->tail;
                this->tail = this->tail->prev;
                this->cache.erase(node);
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @leet end
