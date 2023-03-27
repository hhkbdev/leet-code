#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

class Solution {
	public:
		void nextPermutation(std::vector<int>& nums) {
			std::sort(nums.begin(), nums.end());
			do {
				std::string permutation;
				for (auto num : nums) {
					permutation += std::to_string(num) + ",";
				}
				std::cout << permutation << std::endl;
			} while (std::next_permutation(nums.begin(), nums.end()));
		}


};

int main()
{
	Solution s;
	std::cout << "1, 2, 3" << std::endl;
	std::vector<int> nums1 = {1, 2, 3};
	s.nextPermutation(nums1);

	std::cout << "3, 2, 1" << std::endl;
	std::vector<int> nums2 = {3, 2, 1};
	s.nextPermutation(nums2);

	std::cout << "1, 1, 5" << std::endl;
	std::vector<int> nums3 = {1, 1, 5};
	s.nextPermutation(nums3);


	return 0;
}

