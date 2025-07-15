use std::io::{self, Write};

fn reverse_sentence() -> String {
    loop {
        print!("\nPlease type a sentence and I will reverse the word order:\n");
        io::stdout().flush().unwrap(); // ensure prompt appears before input

        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Failed to read input");

        let trimmed = input.trim();
        if trimmed.is_empty() {
            println!("\nPlease type at least one character.");
            continue;
        }

        let reversed: Vec<&str> = trimmed.split_whitespace().rev().collect();
        return reversed.join(" ");
    }
}

fn print_reversed(reversed: &str) {
    println!("{}", reversed);
}

fn main() {
    let result = reverse_sentence();
    print_reversed(&result);
}
