use std::io;

fn main() {
    print_multiplication_table();
}

fn print_multiplication_table() {
    loop {
        println!(); // extra line before input
        println!("Please enter a number and I will print");
        print!("the multiplication table, to 10, for that number: ");
        io::Write::flush(&mut io::stdout()).unwrap(); // flush to ensure print! shows before input

        let mut user_input = String::new();
        if io::stdin().read_line(&mut user_input).is_ok() {
            if let Ok(number) = user_input.trim().parse::<i32>() {
                println!();
                for i in 1..=10 {
                    println!("{} x {} = {}", number, i, number * i);
                }
                break;
            }
        }

        println!("\nPlease enter a number.\n");
    }
}
