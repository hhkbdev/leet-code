#include <iostream>
#include <vector>

class Solution {
	private:
		std::vector<int> result;
	public:
		std::vector<int> twoSum(std::vector<int>& nums, int target) {

			for (int i = 0; i < nums.size(); i++) {
				if (result.size() > 1){
					break;
				}
				for (int j = i+1; j < nums.size(); j++) {
					if ((nums[i] + nums[j]) == target) {
						result.push_back(i);
						result.push_back(j);
						break;
					}
				}
				std::cout << i << std::endl;
			}



			return result;
		}
};

int main()
{
	Solution solution;
	std::vector<int> nums = { 2, 7, 11, 15 };
	std::vector<int> result = solution.twoSum(nums, 9);
	std::cout << result[0] << " " << result[1] << std::endl;

	return 0;
}

