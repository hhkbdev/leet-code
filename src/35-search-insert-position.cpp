#include <iostream>
#include <vector>

class Solution {
	public:
		int searchInsert(std::vector<int>& nums, int target) {
			int i = 0;
			for (i = 0; i < nums.size(); i++) {
				if (nums[i] >= target) {
					break;
				}
			}
			return i;
		}
};

int main()
{
	Solution s;
	std::vector<int> nums = {1, 3, 5, 6};

	std::cout << s.searchInsert(nums, 5) << std::endl;
	std::cout << s.searchInsert(nums, 2) << std::endl;
	std::cout << s.searchInsert(nums, 7) << std::endl;

	return 0;
}

