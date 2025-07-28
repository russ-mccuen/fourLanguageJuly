#include <iostream>
#include <vector>

bool isMountainArray(const std::vector<int>& arr) {
    std::cout << "Input array: ";
    for (int val : arr) std::cout << val << " ";
    std::cout << std::endl;

    int n = arr.size();
    if (n < 3) return false;

    int i = 0;

    // Ascend
    while (i + 1 < n && arr[i] < arr[i + 1]) i++;

    // Peak can't be first or last
    if (i == 0 || i == n - 1) return false;

    // Descend
    while (i + 1 < n && arr[i] > arr[i + 1]) i++;

    return i == n - 1;
}

int main() {
    std::vector<std::vector<int>> testCases = {
        {0, 3, 2, 1},
        {2, 1},
        {3, 5, 5},
        {0, 1, 2, 3, 2, 1, 0}
    };

    for (const auto& test : testCases) {
        bool result = isMountainArray(test);
        std::cout << "Is mountain: " << (result ? "true" : "false") << "\n---\n";
    }

    return 0;
}
