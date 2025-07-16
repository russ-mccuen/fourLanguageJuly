use std::io;

fn is_prime(n: u32) -> bool {
    if n <= 1 {
        return false;
    }
    for i in 2..=((n as f64).sqrt() as u32) {
        if n % i == 0 {
            return false;
        }
    }
    true
}

fn get_user_input() -> u32 {
    loop {
        println!("\nEnter a positive whole number (2 or greater):");
        let mut input = String::new();

        if io::stdin().read_line(&mut input).is_ok() {
            if let Ok(num) = input.trim().parse::<u32>() {
                if num >= 2 {
                    return num;
                }
            }
        }
        println!("Please enter a valid number (2 or greater).");
    }
}

fn print_primes_up_to(n: u32) {
    println!("\nPrime numbers up to {}:", n);
    for i in 2..=n {
        if is_prime(i) {
            print!("{} ", i);
        }
    }
    println!();
}

fn main() {
    let user_num = get_user_input();
    print_primes_up_to(user_num);
}
