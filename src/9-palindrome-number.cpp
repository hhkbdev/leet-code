#include <iostream>
#include <vector>

class Solution {
public:
    bool isPalindrome(int x) {
		if (x < 0) return false;
		if (x < 10) return true;
		std::vector<int> digits;
		while (x > 0) {
			digits.push_back(x % 10);
			x /= 10;
		}
		int i = 0, j = digits.size() - 1;
		while (i < j) {
			if (digits[i] != digits[j]) return false;
			i++;
			j--;
		}
		return true;
        
    }
};

int main()
{
	Solution s;
	std::cout << s.isPalindrome(121) << std::endl;
    return 0;
}

