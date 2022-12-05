#include <iostream>
#include <vector>
#include <string>

class Solution {
	public:
		std::string longestPalindrome(std::string s) {
			int n = s.size();
			std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
			int maxLen = 1;
			int start = 0;
			for (int i = 0; i < n; i++) {
				dp[i][i] = true;
				if (i < n - 1 && s[i] == s[i + 1]) {
					dp[i][i + 1] = true;
					maxLen = 2;
					start = i;
				}
			}
			for (int len = 3; len <= n; len++) {
				for (int i = 0; i + len - 1 < n; i++) {
					int j = i + len - 1;
					if (s[i] == s[j] && dp[i + 1][j - 1]) {
						dp[i][j] = true;
						maxLen = len;
						start = i;
					}
				}
			}
			return s.substr(start, maxLen);
		}
};

int main()
{
	Solution s;

	std::cout << s.longestPalindrome("babad") << std::endl;
	std::cout << s.longestPalindrome("cbbd") << std::endl;
	std::cout << s.longestPalindrome("a") << std::endl;
	std::cout << s.longestPalindrome("ac") << std::endl;

    return 0;
}

