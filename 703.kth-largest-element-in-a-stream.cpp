// @leet start
#include <algorithm>
class KthLargest {
private:
    vector<int> heap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            this->add(num);
        }
    }
    
    int add(int val) {
        if (this->heap.size() < this->k) {
            this->heap.push_back(val);
            std::push_heap(heap.begin(), heap.end(), std::greater<>{});
        } else {
            if (this->heap[0] < val) {
                std::pop_heap(heap.begin(), heap.end(), std::greater<>{});
                this->heap.pop_back();
                this->heap.push_back(val);
                std::push_heap(heap.begin(), heap.end(), std::greater<>{});
            }
        }
        return this->heap[0];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @leet end
