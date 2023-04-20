#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

class Solution {
public:
    void next_permutation(std::vector<int> &nums) {
        std::vector<std::vector<int>> permutations = this->get_permutations(nums);

        auto it = std::find_if(permutations.begin(), permutations.end(), [&nums](std::vector<int> permutation) {
            bool is_equal = true;

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] != permutation[i]) {
                    is_equal = false;
                    break;
                }
            }

            return is_equal;
        });


        if (it != permutations.end() - 1) {
            nums = *(it + 1);
        } else {
            nums = permutations[0];
        }
    }

private:
    std::vector<std::vector<int>> get_permutations(std::vector<int> nums) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        do {
            result.push_back(nums);
        } while (std::next_permutation(nums.begin(), nums.end()));


        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    Solution s;
    std::cout << "1, 2, 3" << std::endl;
    std::vector<int> nums1 = {1, 2, 3};
    s.next_permutation(nums1);
    for (auto i: nums1) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "3, 2, 1" << std::endl;
    std::vector<int> nums2 = {3, 2, 1};
    s.next_permutation(nums2);
    for (auto i: nums2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "1, 1, 5" << std::endl;
    std::vector<int> nums3 = {1, 1, 5};
    s.next_permutation(nums3);
    for (auto i: nums3) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

