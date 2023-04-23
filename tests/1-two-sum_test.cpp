#include "1-two-sum.h"

#include <gtest/gtest.h>

namespace leetcode_1 {
namespace {
TEST(LeetCode1Test, Test1) {
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  std::vector<int> result = {0, 1};
  Solution solution;
  EXPECT_EQ(solution.twoSum(nums, target), result);
}
}
}
