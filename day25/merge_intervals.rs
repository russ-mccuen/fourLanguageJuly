use rand::{random_range, rng};
use rand::seq::SliceRandom;

fn merge_intervals(mut intervals: Vec<(i32, i32)>) -> Vec<(i32, i32)> {
    if intervals.is_empty() {
        return vec![];
    }

    intervals.sort_by_key(|x| x.0);
    let mut merged = vec![intervals[0]];

    for current in intervals.into_iter().skip(1) {
        let last = merged.last_mut().unwrap();
        if current.0 <= last.1 {
            last.1 = last.1.max(current.1);
        } else {
            merged.push(current);
        }
    }

    merged
}

fn generate_test_case() -> Vec<(i32, i32)> {
    let len = random_range(5..=10);
    let mut intervals = Vec::with_capacity(len);
    for _ in 0..len {
        let start = random_range(0..=20);
        let end = start + random_range(1..=10);
        intervals.push((start, end));
    }
    intervals.shuffle(&mut rng());
    intervals
}

fn main() {
    let intervals = generate_test_case();
    println!("Input: {:?}", intervals);
    let merged = merge_intervals(intervals);
    println!("Merged: {:?}", merged);
}
