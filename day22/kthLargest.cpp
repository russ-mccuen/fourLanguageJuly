#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <algorithm>

int findKthLargest(const std::vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > static_cast<size_t>(k)) {
            minHeap.pop();
        }
    }

    return minHeap.top();
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int length = std::rand() % 21 + 10; // 10 to 30
    std::vector<int> nums(length);

    for (int& n : nums) {
        n = std::rand() % 101; // 0 to 100
    }

    int k = std::rand() % length + 1; // 1 to length

    std::cout << "Input: ";
    for (int n : nums) std::cout << n << " ";
    std::cout << "\nk: " << k << "\n";
    std::cout << k << "th largest element: " << findKthLargest(nums, k) << "\n";

    return 0;
}
