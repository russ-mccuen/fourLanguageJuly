use rand::{thread_rng, Rng};
use std::collections::HashSet;

fn longest_consecutive(nums: &[i32]) -> usize {
    let num_set: HashSet<i32> = nums.iter().cloned().collect();
    let mut longest = 0;

    for &num in &num_set {
        if !num_set.contains(&(num - 1)) {
            let mut current = num;
            let mut streak = 1;

            while num_set.contains(&(current + 1)) {
                current += 1;
                streak += 1;
            }

            longest = longest.max(streak);
        }
    }

    longest
}

fn main() {
    let mut rng = thread_rng();
    let length = rng.gen_range(10..=30);

    let mut unique = HashSet::new();
    while unique.len() < length {
        unique.insert(rng.gen_range(0..100));
    }

    let nums: Vec<i32> = unique.into_iter().collect();
    println!("Input: {:?}", nums);
    println!(
        "Longest consecutive sequence length: {}",
        longest_consecutive(&nums)
    );
}
