#include <iostream>
#include <vector>

class Solution {
	public:
		bool isValid(std::string s) {
			std::vector<char> stack;
			for (auto c : s) {
				if (c == '(' || c == '[' || c == '{') {
					stack.push_back(c);
				} else {
					if (stack.empty()) {
						return false;
					}
					char top = stack.back();
					stack.pop_back();
					if (c == ')' && top != '(') {
						return false;
					}
					if (c == ']' && top != '[') {
						return false;
					}
					if (c == '}' && top != '{') {
						return false;
					}
				}
			}
			return stack.empty();
		}
};

int main()
{
	Solution s;
	std::cout << s.isValid("()") << std::endl;
	std::cout << s.isValid("()[]{}") << std::endl;
	std::cout << s.isValid("(]") << std::endl;
	std::cout << s.isValid("([)]") << std::endl;
	std::cout << s.isValid("{[]}") << std::endl;

    return 0;
}

