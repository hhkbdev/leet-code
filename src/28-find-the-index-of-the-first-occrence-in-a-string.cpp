#include <iostream>
#include <vector>

class Solution {
	public:
		int strStr(std::string haystack, std::string needle) {
			if (needle.empty()) {
				return 0;
			}
			if (haystack.empty()) {
				return -1;
			}
			int i = 0;
			int j = 0;
			int k = 0;
			while (i < haystack.size()) {
				if (haystack[i] == needle[j]) {
					if (j == 0) {
						k = i;
					}
					j++;
					if (j == needle.size()) {
						return k;
					}
				} else {
					j = 0;
				}
				i++;
			}
			return -1;
		}
};

int main()
{
	Solution s;
	std::cout << s.strStr("sadbutsad", "sad") << std::endl;
	std::cout << s.strStr("leetcode", "leeto") << std::endl;
	std::cout << s.strStr("mississippi", "issip") << std::endl;
	return 0;
}

