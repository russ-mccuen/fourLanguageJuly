use std::io;

fn main() {
    println!("Enter a word or words and I will count the number of vowels:");

    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read input");

    let input = input.to_lowercase();
    let vowel_count = input.chars().filter(|c| "aeiou".contains(*c)).count();

    println!(
        "The number of vowels in your input is {} (not including y).",
        vowel_count
    );
}
