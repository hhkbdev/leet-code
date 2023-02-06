#include <iostream>
#include <vector>

class Solution {
	public:
		int removeElement(std::vector<int>& nums, int val) {
			int i = 0;
			for (int j = 0; j < nums.size(); j++) {
				if (nums[j] != val) {
					nums[i] = nums[j];
					i++;
				}
			}
			return i;
		}
};

int main()
{
	Solution s;
	std::vector<int> nums = {3, 2, 2, 3};
	int val = 3;
	int len = s.removeElement(nums, val);
	for (int i = 0; i < len; i++) {
		std::cout << nums[i] << std::endl;
	}
	return 0;
}

