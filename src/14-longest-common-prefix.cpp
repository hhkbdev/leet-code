#include <iostream>
#include <vector>

class Solution {
public:
	std::string longestCommonPrefix(std::vector<std::string>& strs) {
		if (strs.empty()) return "";
		std::string prefix = strs[0];
		for (int i = 1; i < strs.size(); i++) {
			int j = 0;
			for (; j < prefix.size() && j < strs[i].size(); j++) {
				if (prefix[j] != strs[i][j]) break;
			}
			prefix = prefix.substr(0, j);
			if (prefix.empty()) return "";
		}
		return prefix;
	}
};

int main()
{
	std::vector<std::string> strs = {"flower","flow","flight"};
	std::cout << Solution().longestCommonPrefix(strs) << std::endl;

    return 0;
}

