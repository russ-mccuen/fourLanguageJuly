use std::collections::{HashSet, VecDeque};

fn one_letter_diff(a: &str, b: &str) -> bool {
    a.chars()
        .zip(b.chars())
        .filter(|(ac, bc)| ac != bc)
        .count()
        == 1
}

fn word_ladder(start: &str, end: &str, dict: &[&str]) -> Vec<String> {
    println!("Start word: {}", start);
    println!("End word: {}", end);
    println!("Dictionary: {:?}\n", dict);

    let word_set: HashSet<&str> = dict.iter().copied().collect();
    if !word_set.contains(end) {
        println!("End word not in dictionary.");
        return vec![];
    }

    let mut queue = VecDeque::new();
    queue.push_back(vec![start.to_string()]);
    let mut visited = HashSet::new();
    visited.insert(start.to_string());

    while let Some(path) = queue.pop_front() {
        let current = path.last().unwrap();

        println!("Current path: {:?}", path);

        if current == end {
            return path;
        }

        for &word in &word_set {
            if !visited.contains(word) && one_letter_diff(current, word) {
                let mut new_path = path.clone();
                new_path.push(word.to_string());
                visited.insert(word.to_string());
                queue.push_back(new_path);
            }
        }
    }

    println!("No transformation path found.");
    vec![]
}

fn main() {
    let start = "hit";
    let end = "cog";
    let dictionary = ["hot", "dot", "dog", "lot", "log", "cog"];

    let result = word_ladder(start, end, &dictionary);

    println!("\nFinal transformation path:");
    for word in result {
        print!("{} ", word);
    }
    println!();
}
