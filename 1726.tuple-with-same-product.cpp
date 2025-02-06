// @leet start
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> prods;
        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                int b = nums[j];
                int p = a * b;
                if (prods.find(a * b) == prods.end()) {
                    prods[p] = 0;
                } else {
                    result += prods[p] * 2;
                }
                prods[p] += 2;
            }
        }

        return result * 2;
        
    }
};
// @leet end
