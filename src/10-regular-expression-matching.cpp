#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        
    }
};

int main()
{
	Solution s;
	std::cout << s.isMatch("aa", "a") << std::endl;
	std::cout << s.isMatch("aa", "a*") << std::endl;
	std::cout << s.isMatch("ab", ".*") << std::endl;

    return 0;
}

