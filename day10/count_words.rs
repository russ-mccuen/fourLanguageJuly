use std::collections::HashMap;
use std::io::{self, Write};

fn main() {
    // Prompt the user
    print!("Enter a sentence: ");
    io::stdout().flush().unwrap(); // Ensures prompt appears before user types

    // Read user input
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    // Convert to lowercase for case-insensitive comparison
    let input = input.to_lowercase();

    // Create a HashMap to store word frequencies
    let mut word_counts = HashMap::new();

    // Split sentence into words and count them
    for word in input.split_whitespace() {
        *word_counts.entry(word.to_string()).or_insert(0) += 1;
    }

    // Display word frequencies
    for (word, count) in &word_counts {
        println!("{}: {}", word, count);
    }
}
