// @leet start
#include <unordered_map>

class LinkedNode {
public:
  int key;
  int value;
  LinkedNode *prev;
  LinkedNode *next;

  LinkedNode(int key, int value) {
    this->key = key;
    this->value = value;
    this->prev = nullptr;
    this->next = nullptr;
  }
};

class LRUCache {
private:
  int capacity;
  int curr_capacity;
  LinkedNode *head;
  LinkedNode *tail;
  unordered_map<int, LinkedNode *> map;

public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    this->curr_capacity = 0;
    this->head = nullptr;
    this->tail = nullptr;
  }

  void moveToFront(int key) {
    LinkedNode *node = this->map[key];
    if (this->head == node) {
            return;
    }

    if (this->tail == node) {
        this->tail = node->prev;
    }
    if (node->prev != nullptr) {
      node->prev->next = node->next;
    }

    if (node->next != nullptr) {
      node->next->prev = node->prev;
    }

    node->prev = nullptr;
    node->next = this->head;
    if (this->head == nullptr) {
      this->head = node;
      this->tail = node;
    } else {
      this->head->prev = node;
    }

    this->head = node;
  }

  int get(int key) {
    if (this->map.find(key) == this->map.end()) {
      return -1;
    }

    this->moveToFront(key);

    return this->map[key]->value;
  }

  void put(int key, int value) {
    if (this->map.find(key) == this->map.end()) {
      LinkedNode *curr_node = new LinkedNode(key, value);
      if (this->head == nullptr) {
        this->head = curr_node;
        this->tail = curr_node;
      } else {
        curr_node->next = this->head;
        this->head->prev = curr_node;
        this->head = curr_node;
      }
      this->map[key] = curr_node;
      this->curr_capacity++;
      if (this->curr_capacity > this->capacity) {
        if (this->tail != nullptr) {
          LinkedNode *temp = this->tail;
          this->tail = this->tail->prev;
          if (this->tail != nullptr) {
            this->tail->next = nullptr;
          }
          this->map.erase(temp->key);
          delete temp;
          this->curr_capacity--;
        }
      }
    } else {
      this->map[key]->value = value;
      this->moveToFront(key);
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @leet end
