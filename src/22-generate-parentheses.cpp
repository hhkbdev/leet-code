#include <iostream>
#include <vector>

class Solution {
	private:
		void generateParenthesis(int left, int right, std::string s, std::vector<std::string> &result) {
			if (left == 0 && right == 0) {
				result.push_back(s);
				return;
			}
			if (left > 0) {
				generateParenthesis(left - 1, right, s + "(", result);
			}
			if (right > left) {
				generateParenthesis(left, right - 1, s + ")", result);
			}
		}
	public:
		std::vector<std::string> generateParenthesis(int n) {
			std::vector<std::string> result;
			generateParenthesis(n, n, "", result);
			return result;
		}
};

int main()
{
	Solution s;
	std::vector<std::string> result = s.generateParenthesis(3);

	for (auto &s : result) {
		std::cout << s << std::endl;
	}

		 
	return 0;
}

