use rand::random_range;

fn product_except_self(nums: &[i32]) -> Vec<i32> {
    let n = nums.len();
    let mut output = vec![1; n];

    // Prefix pass
    let mut prefix = 1;
    for i in 0..n {
        output[i] = prefix;
        prefix *= nums[i];
    }

    // Suffix pass
    let mut suffix = 1;
    for i in (0..n).rev() {
        output[i] *= suffix;
        suffix *= nums[i];
    }

    output
}

fn main() {
    let len = random_range(5..=10);
    let nums: Vec<i32> = (0..len).map(|_| random_range(1..=10)).collect();

    println!("Input: {:?}", nums);
    let result = product_except_self(&nums);
    println!("Output: {:?}", result);
}
