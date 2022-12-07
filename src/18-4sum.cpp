#include <iostream>
#include <vector>

class Solution {
	public:
		std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
			std::vector<std::vector<int>> result;
			if (nums.size() < 4) return result;
			std::sort(nums.begin(), nums.end());
			for (int i = 0; i < nums.size() - 3; i++) {
				if (i > 0 && nums[i] == nums[i - 1]) continue;
				for (int j = i + 1; j < nums.size() - 2; j++) {
					if (j > i + 1 && nums[j] == nums[j - 1]) continue;
					int k = j + 1;
					int l = nums.size() - 1;
					while (k < l) {
						long long flag = target - (long long) nums[i] - (long long) nums[j] - (long long) nums[k] - (long long) nums[l];
						if (flag == 0) {
							result.push_back({nums[i], nums[j], nums[k], nums[l]});
							while (k < l && nums[k] == nums[k + 1]) k++;
							while (k < l && nums[l] == nums[l - 1]) l--;
							k++;
							l--;
						} else if (flag > 0) {
							k++;
						} else {
							l--;
						}
					}
				}
			}
			return result;
		}
};

int main()
{
	Solution s;
	std::vector<int> nums = {1, 0, -1, 0, -2, 2};
	auto result = s.fourSum(nums, 0);
	for (auto &v : result) {
		for (auto &i : v) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}


	return 0;
}

