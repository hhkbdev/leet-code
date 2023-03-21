#include <iostream>
#include <vector>

class Solution {
	public:
		int strStr(std::string haystack, std::string needle) {
            if (needle.empty()) return 0;
            if (haystack.empty()) return -1;
            if (haystack.size() < needle.size()) return -1;
            int i = 0;
            int j = 0;
            while (i < haystack.size()) {
                if (haystack[i] == needle[j]) {
                    if (j == needle.size() - 1) {
                        return i - j;
                    }
                    ++i;
                    ++j;
                } else {
                    i = i - j + 1;
                    j = 0;
                }
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

