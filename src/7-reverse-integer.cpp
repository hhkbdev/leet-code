#include <iostream>
#include <vector>

class Solution {
public:
    int reverse(int x) {

		if (x == 0) return 0;
		if (x == INT_MIN) return 0;

		int sign = x < 0 ? -1 : 1;
		x = x < 0 ? -x : x;
		int result = 0;
		while (x > 0) {
			int digit = x % 10;
			x /= 10;
			if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
				return 0;
			}
			result = result * 10 + digit;
		}
		return result * sign;
    }
};

int main()
{
	Solution s;
		
	std::cout << s.reverse(321) << std::endl;
	std::cout << s.reverse(-123) << std::endl;
	std::cout << s.reverse(120) << std::endl;

    return 0;
}

