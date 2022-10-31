#include <iostream>
#include <vector>

class Solution {
	public:
		int lengthOfLongestSubstring(std::string s) {
			int max = 0;
			int start = 0;
			int end = 0;
			std::vector<int> map(256, -1);
			while (end < s.length()) {
				if (map[s[end]] >= start) {
					start = map[s[end]] + 1;
				}
				map[s[end]] = end;
				max = std::max(max, end - start + 1);
				end++;
			}
			return max;

		}
};

int main()
{
	Solution s;
	std::cout << s.lengthOfLongestSubstring("abcabcbb") << std::endl;
	std::cout << s.lengthOfLongestSubstring("bbbbb") << std::endl;
	std::cout << s.lengthOfLongestSubstring("pwwkew") << std::endl;

	return 0;
}

