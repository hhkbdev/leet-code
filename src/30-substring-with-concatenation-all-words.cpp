#include <iostream>
#include <vector>
#include <map> 

class Solution {
	public:
		std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
			std::vector<int> result;
			if (words.size() == 0) {
				return result;
			}
			int wordLength = words[0].length();
			int wordCount = words.size();
			int totalLength = wordLength * wordCount;
			if (s.length() < totalLength) {
				return result;
			}
			std::map<std::string, int> wordMap;
			for (int i = 0; i < wordCount; i++) {
				wordMap[words[i]]++;
			}
			for (int i = 0; i < wordLength; i++) {
				int left = i;
				int right = i;
				int count = 0;
				std::map<std::string, int> tempMap;
				while (right + wordLength <= s.length()) {
					std::string word = s.substr(right, wordLength);
					right += wordLength;
					if (wordMap.find(word) != wordMap.end()) {
						tempMap[word]++;
						count++;
						while (tempMap[word] > wordMap[word]) {
							std::string leftWord = s.substr(left, wordLength);
							left += wordLength;
							tempMap[leftWord]--;
							count--;
						}
						if (count == wordCount) {
							result.push_back(left);
						}
					} else {
						tempMap.clear();
						count = 0;
						left = right;
					}
				}
			}
			return result;
		}
};

int main()
{
	Solution s;
	std::vector<std::string> words = {"foo", "bar"};
	std::vector<int> result = s.findSubstring("barfoothefoobarman", words);
	for (auto i : result) {
		std::cout << i << std::endl;
	}
	return 0;
}

