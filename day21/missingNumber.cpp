#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <ctime>

int missingNumber(const std::vector<int>& nums) {
    int n = nums.size();
    int expected_sum = n * (n + 1) / 2;
    int actual_sum = std::accumulate(nums.begin(), nums.end(), 0);
    return expected_sum - actual_sum;
}

int main() {
    std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<int> sizeDist(10, 30);

    int n = sizeDist(rng);
    std::vector<int> full(n + 1);
    std::iota(full.begin(), full.end(), 0); // Fill with 0 to n

    std::uniform_int_distribution<int> removeDist(0, n);
    int missing = full[removeDist(rng)];
    full.erase(std::remove(full.begin(), full.end(), missing), full.end());

    std::shuffle(full.begin(), full.end(), rng);

    std::cout << "Input: ";
    for (int num : full) std::cout << num << " ";
    std::cout << "\nExpected missing number: " << missing << "\n";
    std::cout << "Computed missing number: " << missingNumber(full) << "\n";

    return 0;
}
