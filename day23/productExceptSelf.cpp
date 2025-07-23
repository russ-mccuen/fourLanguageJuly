#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<int> productExceptSelf(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> output(n, 1);

    int prefix = 1;
    for (int i = 0; i < n; ++i) {
        output[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;
    for (int i = n - 1; i >= 0; --i) {
        output[i] *= suffix;
        suffix *= nums[i];
    }

    return output;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int length = std::rand() % 6 + 5; // 5 to 10
    std::vector<int> nums(length);
    for (int& n : nums) {
        n = std::rand() % 10 + 1; // values 1 to 10
    }

    std::cout << "Input: ";
    for (int n : nums) std::cout << n << " ";
    std::cout << "\n";

    std::vector<int> result = productExceptSelf(nums);

    std::cout << "Output: ";
    for (int r : result) std::cout << r << " ";
    std::cout << "\n";

    return 0;
}
