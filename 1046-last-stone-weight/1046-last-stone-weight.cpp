class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
                
        make_heap(stones.begin(), stones.end());
        
        while (!stones.empty()) {
            int y = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            
            if (stones.empty()) {
                return y;
            }
            
            int x = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            
            if (y != x) {
                stones.push_back(y - x);
                push_heap(stones.begin(), stones.end());
            }
            
        }
        
        return 0;
    }
};