use std::io::{self, Write};

fn main() {
    loop {
        print!("Please type a sentence (one or more words): ");
        io::stdout().flush().unwrap(); // Make sure prompt prints before input

        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();

        let words: Vec<&str> = input
            .split_whitespace()
            .collect();

        let count = words.len();

        if count == 0 {
            println!("Input cannot be empty.\n");
            continue;
        } else if count == 1 {
            println!("There is 1 word in your sentence.");
        } else {
            println!("There are {} words in your sentence.", count);
        }

        break;
    }
}
