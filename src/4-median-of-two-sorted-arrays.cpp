#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
 public:
  double findMedianSortedArray(std::vector<int>& nums1,
                               std::vector<int>& nums2) {
    std::vector<int> nums;
    nums.reserve(nums1.size() + nums2.size());
    nums.insert(nums.end(), nums1.begin(), nums1.end());
    nums.insert(nums.end(), nums2.begin(), nums2.end());
    std::sort(nums.begin(), nums.end());

    if (nums.size() % 2 == 0) {
      return (nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2.0;
    } else {
      return nums[nums.size() / 2];
    }
  }
};

int main() {
  std::vector<int> a1 = {1, 3};
  std::vector<int> a2 = {2};

  std::vector<int> b1 = {1, 2};
  std::vector<int> b2 = {3, 4};

  Solution s;
  std::cout << s.findMedianSortedArray(a1, a2) << std::endl;
  std::cout << s.findMedianSortedArray(b1, b2) << std::endl;
  return 0;
}

