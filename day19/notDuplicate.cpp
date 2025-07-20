#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <random>
#include <ctime>

int singleNumber(const std::vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num; // XOR cancels out pairs
    }
    return result;
}

int main() {
    std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<int> lengthDist(10, 20);
    std::uniform_int_distribution<int> valueDist(0, 99);

    int length = lengthDist(rng);

    // Use unordered_set to ensure unique values
    std::unordered_set<int> uniqueVals;
    while (uniqueVals.size() < static_cast<size_t>(length)) {
        uniqueVals.insert(valueDist(rng));
    }

    std::vector<int> vals(uniqueVals.begin(), uniqueVals.end());
    int single = vals.back();
    vals.pop_back(); // Remove the one that appears once

    std::vector<int> nums;
    for (int val : vals) {
        nums.push_back(val);
        nums.push_back(val);
    }
    nums.push_back(single); // Add the single element
    std::shuffle(nums.begin(), nums.end(), rng);

    std::cout << "Input: ";
    for (int n : nums) std::cout << n << " ";
    std::cout << "\nExpected single number: " << single << "\n";
    std::cout << "Computed single number: " << singleNumber(nums) << "\n";

    return 0;
}
