use std::io;

fn main() {
    loop {
        println!("\nPlease enter a positive whole number:");

        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Failed to read input");

        match input.trim().parse::<u32>() {
            Ok(num) if num >= 1 => {
                for i in 1..=num {
                    match (i % 3, i % 5) {
                        (0, 0) => println!("FizzBuzz"),
                        (0, _) => println!("Fizz"),
                        (_, 0) => println!("Buzz"),
                        _ => println!("{}", i),
                    }
                }
                break;
            }
            _ => println!("Please only enter a positive whole number."),
        }
    }
}
