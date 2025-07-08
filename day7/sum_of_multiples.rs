use std::io;

fn main() {
    loop {
        println!("\nPlease enter a positive whole number greater than 1:");

        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Failed to read input");

        match input.trim().parse::<u32>() {
            Ok(n) if n > 1 => {
                let sum: u32 = (1..n).filter(|i| i % 3 == 0 || i % 5 == 0).sum();
                println!("The sum of multiples of 3 or 5 below {} is: {}", n, sum);
                break;
            }
            _ => println!("Please only enter a positive whole number greater than 1."),
        }
    }
}
