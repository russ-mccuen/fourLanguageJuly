#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <random>
#include <ctime>

int longestConsecutive(const std::vector<int>& nums) {
    std::unordered_set<int> numSet(nums.begin(), nums.end());
    int longest = 0;

    for (int num : numSet) {
        if (numSet.find(num - 1) == numSet.end()) {
            int current = num;
            int streak = 1;

            while (numSet.find(current + 1) != numSet.end()) {
                current++;
                streak++;
            }

            longest = std::max(longest, streak);
        }
    }

    return longest;
}

int main() {
    std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<int> lengthDist(10, 30);
    std::uniform_int_distribution<int> valueDist(0, 99);

    int length = lengthDist(rng);
    std::unordered_set<int> uniqueNums;
    while (uniqueNums.size() < static_cast<size_t>(length)) {
        uniqueNums.insert(valueDist(rng));
    }

    std::vector<int> nums(uniqueNums.begin(), uniqueNums.end());

    std::cout << "Input: ";
    for (int n : nums) std::cout << n << " ";
    std::cout << "\nLongest consecutive sequence length: " << longestConsecutive(nums) << "\n";

    return 0;
}
