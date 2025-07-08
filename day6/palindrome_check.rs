use std::io;

fn main() {
    println!("\nPlease enter a word or phrase:");

    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read input");

    let cleaned: String = input
        .trim()
        .chars()
        .filter(|c| !c.is_whitespace())
        .map(|c| c.to_ascii_lowercase())
        .collect();

    let reversed: String = cleaned.chars().rev().collect();

    if cleaned.is_empty() {
        println!("You didn't enter anything.");
    } else if cleaned == reversed {
        println!("This is a palindrome.");
    } else {
        println!("This is not a palindrome.");
    }
}
