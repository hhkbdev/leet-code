#include <iostream>
#include <vector>

class Solution {
	public:
        int removeDuplicates(std::vector<int>& nums) {
            if (nums.size() == 0) return 0;
            int i = 0;
            for (int j = 1; j < nums.size(); j++) {
                if (nums[j] != nums[i]) {
                    i++;
                    nums[i] = nums[j];
                }
            }
            return i + 1;
        }
};

int main()
{
    std::vector<int> nums = {1, 1, 2};
    Solution s;
    int len = s.removeDuplicates(nums);
    for (int i = 0; i < len; i++) {
        std::cout << nums[i] << std::endl;
    }
	return 0;
}

