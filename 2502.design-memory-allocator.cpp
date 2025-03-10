// @leet start
#include <unordered_map>
class Allocator {
private: 
    bool *memmap;
    int max_size;
    std::unordered_map<int, vector<pair<int, int>>> map;
public:
    Allocator(int n) {
        this->max_size = n;
        this->memmap = new bool[n]();
        for (int i = 0; i < n; i++) {
            this->memmap[i] = false;
        }
    }
    
    int allocate(int size, int mID) {
        int idx = 0;
        while (idx < this->max_size) {
            int len = size;
            int ptr = idx;

            while(len > 0 && ptr < this->max_size && !this->memmap[ptr]) {
                len--;
                ptr++;
            }

            if (len <= 0) {
                for (int i = 0; i < size; i++) {
                    this->memmap[i + idx] = true;
                }

                if (this->map.find(mID) == this->map.end()) {
                    this->map[mID] = vector<pair<int,int>>();
                }

                this->map[mID].push_back(pair<int, int>(idx, size));
                return idx;
            } else {
                idx = ptr + 1;
            }
        }

        return -1;
        
    }
    
    int freeMemory(int mID) {
        int total = 0;
        if (this->map.find(mID) == this->map.end()) {
            return 0;
        }

        vector<pair<int, int>> &vec = this->map[mID];
        for (pair<int,int> mem : vec) {
            for (int i = mem.first; i < (mem.first + mem.second); i++) {
                this->memmap[i] = false;
            }
            total += mem.second;
        }

        this->map.erase(mID);

        return total;
        
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
// @leet end
