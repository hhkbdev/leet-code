#include <iostream>
#include <vector>

class Solution {
	public:
		std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
			std::vector<std::vector<int>> result;
			std::sort(nums.begin(), nums.end());
			for (int i = 0; i < nums.size(); i++) {
				if (i > 0 && nums[i] == nums[i - 1]) continue;
				int target = -nums[i];
				int left = i + 1;
				int right = nums.size() - 1;
				while (left < right) {
					if (nums[left] + nums[right] == target) {
						result.push_back({nums[i], nums[left], nums[right]});
						while (left < right && nums[left] == nums[left + 1]) left++;
						while (left < right && nums[right] == nums[right - 1]) right--;
						left++;
						right--;
					} else if (nums[left] + nums[right] < target) {
						left++;
					} else {
						right--;
					}
				}
			}
			return result;
		}
};

int main()
{
	Solution s;
	std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
	auto result = s.threeSum(nums);
	for (auto& v : result) {
		for (auto& i : v) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}

