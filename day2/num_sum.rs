use std::io;

fn main() {
    loop {
        println!("\nPlease enter a positive whole number:");

        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Failed to read input");

        let trimmed = input.trim();

        if trimmed.chars().all(|c| c.is_ascii_digit()) {
            let sum: u32 = trimmed.chars()
                .map(|c| c.to_digit(10).unwrap())
                .sum();

            println!("The sum of the digits is: {}", sum);
            break;
        } else {
            println!("Please only enter a positive whole number.");
        }
    }
}
