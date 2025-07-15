use std::io::{self, Write};

fn get_upper_count() -> usize {
    loop {
        print!("Please type a sentence and I will tell you how many uppercase letters it has:\n");
        io::stdout().flush().unwrap();

        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();

        if input.trim().is_empty() {
            println!("\nPlease type at least one character.\n");
            continue;
        }

        let count = input.chars().filter(|c| c.is_uppercase()).count();
        return count;
    }
}

fn print_upper_count(count: usize) {
    println!("The number of uppercase letters is {}.", count);
}

fn main() {
    let upper_count = get_upper_count();
    print_upper_count(upper_count);
}
