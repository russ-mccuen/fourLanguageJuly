#include <iostream>
#include <vector>

int trap(const std::vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int left_max = 0, right_max = 0, water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= left_max)
                left_max = height[left];
            else
                water += left_max - height[left];
            ++left;
        } else {
            if (height[right] >= right_max)
                right_max = height[right];
            else
                water += right_max - height[right];
            --right;
        }
    }

    return water;
}

int main() {
    std::vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    std::cout << "Elevation map: ";
    for (int h : height) std::cout << h << " ";
    std::cout << "\nWater trapped: " << trap(height) << "\n";

    return 0;
}
