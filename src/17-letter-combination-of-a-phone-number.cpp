#include <iostream>
#include <vector>

class Solution {

	public:
		std::vector<std::string> letterCombinations(std::string digits) {
			std::vector<std::string> result;
			if (digits.empty()) {
				return result;
			}
			std::vector<std::string> mapping = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
			result.push_back("");
			for (int i = 0; i < digits.size(); i++) {
				std::vector<std::string> temp;
				std::string letters = mapping[digits[i] - '0'];
				for (int j = 0; j < letters.size(); j++) {
					for (int k = 0; k < result.size(); k++) {
						temp.push_back(result[k] + letters[j]);
					}
				}
				result = temp;
			}
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

