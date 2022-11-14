#include <iostream>
#include <vector>
#include <string>

class Solution {
	public:
		std::string intToRoman(int num) {
			std::vector<std::string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
			std::vector<int> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
			std::string result;
			for (int i = 0; i < value.size(); i++) {
				while (num >= value[i]) {
					num -= value[i];
					result += roman[i];
				}
			}
			return result;
		}
};

int main()
{
	Solution s;
	std::cout << s.intToRoman(3) << std::endl;
	std::cout << s.intToRoman(4) << std::endl;
	std::cout << s.intToRoman(9) << std::endl;
	std::cout << s.intToRoman(58) << std::endl;
	std::cout << s.intToRoman(1994) << std::endl;

	return 0;
}

