#include <iostream>
#include <vector>

class Solution {
	public:
		int threeSumClosest(std::vector<int>& nums, int target) {
			int n = nums.size();
			int ans = nums[0] + nums[1] + nums[2];
			std::sort(nums.begin(), nums.end());
			for (int i = 0; i < n; i++) {
				int j = i + 1;
				int k = n - 1;
				while (j < k) {
					int sum = nums[i] + nums[j] + nums[k];
					if (abs(sum - target) < abs(ans - target)) {
						ans = sum;
					}
					if (sum > target) {
						k--;
					} else if (sum < target) {
						j++;
					} else {
						return ans;
					}
				}
			}
			return ans;

		}
};

int main()
{
	Solution s;
	std::vector<int> nums = {-1, 2, 1, -4};
	std::cout << s.threeSumClosest(nums, 1) << std::endl;

    return 0;
}

