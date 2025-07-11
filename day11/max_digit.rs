use std::io;

fn main() {
    loop {
        println!("Enter a number and I will extract the maximum digit:");

        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Failed to read input");

        let trimmed = input.trim();

        if trimmed.chars().all(|c| c.is_ascii_digit()) {
            let max_digit = trimmed
                .chars()
                .map(|c| c.to_digit(10).unwrap())
                .max()
                .unwrap();
            println!("The maximum digit is: {}", max_digit);
            break;
        } else {
            println!("Please enter only digits.\n");
        }
    }
}
