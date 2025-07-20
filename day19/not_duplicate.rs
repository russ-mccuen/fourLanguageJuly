use rand::{seq::SliceRandom, thread_rng, Rng};
use std::collections::HashSet;

fn single_number(nums: &[i32]) -> i32 {
    nums.iter().fold(0, |acc, &x| acc ^ x) // XOR cancels out duplicates
}

fn main() {
    let mut rng = thread_rng();
    let length = rng.gen_range(10..=20);

    // HashSet ensures unique values
    let mut unique_vals = HashSet::new();
    while unique_vals.len() < length {
        unique_vals.insert(rng.gen_range(0..100));
    }

    let mut vals: Vec<i32> = unique_vals.into_iter().collect();
    let single = vals.pop().unwrap(); // One value appears once

    let mut nums: Vec<i32> = vals
        .iter()
        .flat_map(|&x| vec![x, x]) // Each remaining value appears twice
        .collect();

    nums.push(single);
    nums.shuffle(&mut rng);

    println!("Input: {:?}", nums);
    println!("Expected single number: {}", single);
    println!("Computed single number: {}", single_number(&nums));
}
