fn compress_string(s: &str) -> String {
    if s.is_empty() {
        println!("Original: \"\"");
        println!("Compressed: \"\"");
        return String::new();
    }

    let mut compressed = String::new();
    let mut count = 1;
    let chars: Vec<char> = s.chars().collect();

    for i in 1..chars.len() {
        if chars[i] == chars[i - 1] {
            count += 1;
        } else {
            compressed.push(chars[i - 1]);
            compressed.push_str(&count.to_string());
            count = 1;
        }
    }

    compressed.push(*chars.last().unwrap());
    compressed.push_str(&count.to_string());

    println!("Original: {}", s);
    println!("Compressed: {}", if compressed.len() < s.len() { &compressed } else { s });

    if compressed.len() < s.len() {
        compressed
    } else {
        s.to_string()
    }
}

fn main() {
    compress_string("aabcccccaaa");
    compress_string("abc");
}
