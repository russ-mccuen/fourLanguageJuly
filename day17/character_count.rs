use std::io::{self, Write};

fn main() {
    let sentence = loop {
        print!("Please enter a sentence:\n");
        io::stdout().flush().unwrap();

        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let trimmed = input.trim();

        if !trimmed.is_empty() {
            break trimmed.to_string();
        } else {
            println!("\nPlease enter at least one character.\n");
        }
    };

    print!("\nPlease enter a character to count:\n");
    io::stdout().flush().unwrap();

    let mut char_input = String::new();
    io::stdin().read_line(&mut char_input).unwrap();
    let target_char = char_input.trim().chars().next().unwrap_or('\0');

    let count = sentence.chars().filter(|&c| c == target_char).count();

    println!(
        "\nThe character '{}' appears {} time{}.",
        target_char,
        count,
        if count == 1 { "" } else { "s" }
    );
}
