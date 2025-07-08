use std::io;

fn main() {
    loop {
        println!("\nPlease enter a positive whole number (1 or greater):");

        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Failed to read input");

        match input.trim().parse::<u32>() {
            Ok(n) if n >= 1 => {
                let result = (1..=n as u128).product::<u128>();
                println!("The factorial of {} is {}.", n, result);
                break;
            }
            _ => println!("Please only enter a positive whole number."),
        }
    }
}
