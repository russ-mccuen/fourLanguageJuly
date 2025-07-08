use std::io;

fn main() {
    println!("\nPlease enter a word or phrase:");

    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read input");

    let trimmed = input.trim();
    if trimmed.is_empty() {
        println!("You didn't enter anything.");
    } else {
        let reversed: String = trimmed.chars().rev().collect();
        println!("Reversed: {}", reversed);
    }
}
