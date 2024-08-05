#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int32_t, int32_t> candidates;
    for (int i = 0; i <= nums.size(); ++i) {
      auto candidate = candidates.find(target - nums[i]);
      if (candidate != candidates.end()) {
        return {i, candidate->second};
      }
      candidates.insert(std::pair(nums[i], i));
    }
    return std::vector<int>();
  }
};