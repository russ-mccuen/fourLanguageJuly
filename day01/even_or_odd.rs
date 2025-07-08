use std::io;

fn main() {
    loop {
        println!("\nPlease enter a whole number (no decimals):");

        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Failed to read input");

        match input.trim().parse::<i32>() {
            Ok(num) => {
                if num % 2 == 0 {
                    println!("The number is even.");
                } else {
                    println!("The number is odd.");
                }
                break;
            }
            Err(_) => {
                println!("Please enter a valid whole number.");
            }
        }
    }
}
