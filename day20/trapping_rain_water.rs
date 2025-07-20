fn trap(height: &[i32]) -> i32 {
    let (mut left, mut right) = (0, height.len() - 1);
    let (mut left_max, mut right_max) = (0, 0);
    let mut water = 0;

    while left < right {
        if height[left] < height[right] {
            if height[left] >= left_max {
                left_max = height[left];
            } else {
                water += left_max - height[left];
            }
            left += 1;
        } else {
            if height[right] >= right_max {
                right_max = height[right];
            } else {
                water += right_max - height[right];
            }
            right -= 1;
        }
    }

    water
}

fn main() {
    let height = vec![0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1];
    println!("Elevation map: {:?}", height);
    println!("Water trapped: {}", trap(&height));
}
