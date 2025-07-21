use rand::{rng, random_range, seq::SliceRandom};

fn missing_number(nums: &[usize]) -> usize {
    let n = nums.len();
    let expected_sum = n * (n + 1) / 2;
    let actual_sum: usize = nums.iter().sum();
    expected_sum - actual_sum
}

fn main() {
    let mut rng = rng();
    let n = random_range(10..=30);

    let mut full: Vec<usize> = (0..=n).collect();
    let missing_index = random_range(0..=n);
    let missing = full.remove(missing_index);
    full.shuffle(&mut rng);

    println!("Input: {:?}", full);
    println!("Expected missing number: {}", missing);
    println!("Computed missing number: {}", missing_number(&full));
}
