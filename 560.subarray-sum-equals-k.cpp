// @leet start
#include <unordered_map>
class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    std::unordered_map<int, int> map;
    int result = 0;
    int curr_sum = 0;

    if (nums.size() == 1 && nums[0] != k) {
            return 0;
    }

    for (int i = 0; i < nums.size(); i++) {
      curr_sum += nums[i];
      if (map.find(curr_sum) == map.end()) {
        map[curr_sum] = 0;
      }
      map[curr_sum]++;
    }

    map[0]++;

    for (const auto &[key, value] : map) {
      if (map.find(key - k) != map.end()) {
        result += map[key - k];
      }
    }

    return result;
  }
};
// @leet end
