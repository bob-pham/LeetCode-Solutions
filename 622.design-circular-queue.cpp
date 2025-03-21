// @leet start
class MyCircularQueue {
private:
    int *queue;
    int capacity;
    int front;
    int back;
    int size;
public:
    MyCircularQueue(int k) {
        this->queue = new int[k];
        this->capacity = k;
        this->front = 0;
        this->back = 0;
        this->size = 0;
    }
    
    bool enQueue(int value) {
        if (this->isFull()) {
            return false;
        }

        this->size++;
        this->queue[this->back] = value;
        this->back = (this->back + 1) % this->capacity;
        return true;
    }
    
    bool deQueue() {
        if (this->isEmpty()) {
            return false;
        }

        this->size--;
        this->front = (this->front + 1) % this->capacity;
        
        return true;
        
    }
    
    int Front() {
        if (this->isEmpty()) {
            return -1;
        }

        return this->queue[this->front];
    }
    
    int Rear() {
        if (this->isEmpty()) {
            return -1;
        }

        return this->queue[(((this->back - 1) % this->capacity) + this->capacity) % this->capacity];
    }
    
    bool isEmpty() {
       return this->size == 0; 
    }
    
    bool isFull() {
       return this->size == this->capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @leet end
