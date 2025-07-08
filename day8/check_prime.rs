use std::io;

fn is_prime(num: i32) -> bool {
    if num <= 1 {
        return false;
    }
    if num == 2 {
        return true;
    }
    if num % 2 == 0 {
        return false;
    }
    let sqrt = (num as f64).sqrt() as i32;
    for i in (3..=sqrt).step_by(2) {
        if num % i == 0 {
            return false;
        }
    }
    true
}

fn main() {
    loop {
        println!("Please enter a number and I will tell you if it is prime: ");

        let mut input = String::new();
        if let Err(_) = io::stdin().read_line(&mut input) {
            println!("\nFailed to read input.\n");
            continue;
        }

        match input.trim().parse::<i32>() {
            Ok(num) => {
                if is_prime(num) {
                    println!("{} is a prime number.", num);
                } else {
                    println!("{} is not a prime number.", num);
                }
                break;
            }
            Err(_) => {
                println!("\nPlease only enter a number.\n");
            }
        }
    }
}
