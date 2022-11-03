#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int myAtoi(std::string s) {
		int i = 0;
		int sign = 1;
		int result = 0;
		while (i < s.size() && s[i] == ' ') {
			i++;
		}
		if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
			sign = (s[i] == '+') ? 1 : -1;
			i++;
		}
		while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
			if (result > INT_MAX / 10 || (result == INT_MAX / 10 && s[i] - '0' > 7)) {
				return (sign == 1) ? INT_MAX : INT_MIN;
			}
			result = result * 10 + (s[i] - '0');
			i++;
		}
		return result * sign;
        
    }
};

int main()
{
	Solution s;
	std::cout << s.myAtoi("42") << std::endl;
	std::cout << s.myAtoi("   -42") << std::endl;

    return 0;
}

