// @leet start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::make_heap(stones.begin(), stones.end());

        while(stones.size() > 1) {
            std::pop_heap(stones.begin(), stones.end());
            int a = stones.back();
            stones.pop_back();
            std::pop_heap(stones.begin(), stones.end());
            int b = stones.back();
            stones.pop_back();
            if (a == b) {
                continue;
            }
            stones.push_back(a - b)
            std::push_heap(stones.begin(), stones.end());
        }

        return stones.size() == 0 ? 0 : stones[0];
    }
};
// @leet end
