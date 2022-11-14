#include <iostream>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
		int max = 0;
		int i = 0;
		int j = height.size() - 1;
		while (i < j) {
			int area = (j - i) * std::min(height[i], height[j]);
			if (area > max) {
				max = area;
			}
			if (height[i] < height[j]) {
				i++;
			} else {
				j--;
			}
		}
		return max;
    }
};

int main()
{
	Solution s;
	std::vector<int> v = {1,8,6,2,5,4,8,3,7};
	std::cout << s.maxArea(v) << std::endl;
    return 0;
}

