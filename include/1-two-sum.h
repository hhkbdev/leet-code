#ifndef LEETCODEPROJECT_INCLUDE_1_TWO_SUM_H_
#define LEETCODEPROJECT_INCLUDE_1_TWO_SUM_H_

#include <vector>
#include <iostream>

namespace leetcode_1 {
class Solution {
 public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
      if (result.size() > 1) {
        break;
      }
      for (int j = i + 1; j < nums.size(); j++) {
        if ((nums[i] + nums[j]) == target) {
          result.push_back(i);
          result.push_back(j);
          break;
        }
      }
      std::cout << i << std::endl;
    }
    return result;
  };
 private:
  std::vector<int> result;
};
}

#endif //LEETCODEPROJECT_INCLUDE_1_TWO_SUM_H_
