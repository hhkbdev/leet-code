#include <iostream>
#include <vector>

class Solution {

	public:
		std::vector<std::string> letterCombinations(std::string digits) {
			std::vector<std::string> result;
			if (digits.empty()) {
				return result;
			}
			std::vector<std::string> dict = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
			std::string path;
			dfs(digits, 0, dict, path, result);
			return result;
		}
};

int main()
{
	Solution s;
	std::vector<std::string> ret = s.letterCombinations("23");
	for (auto &s : ret) {
		std::cout << s << std::endl;
	}

    return 0;
}

