fn is_mountain_array(arr: &[i32]) -> bool {
    println!("Input array: {:?}", arr);
    let n = arr.len();
    if n < 3 {
        return false;
    }

    let mut i = 0;

    // Ascend
    while i + 1 < n && arr[i] < arr[i + 1] {
        i += 1;
    }

    // Peak can't be first or last
    if i == 0 || i == n - 1 {
        return false;
    }

    // Descend
    while i + 1 < n && arr[i] > arr[i + 1] {
        i += 1;
    }

    i == n - 1
}

fn main() {
    let test_cases = vec![
        vec![0, 3, 2, 1],
        vec![2, 1],
        vec![3, 5, 5],
        vec![0, 1, 2, 3, 2, 1, 0],
    ];

    for case in test_cases {
        let result = is_mountain_array(&case);
        println!("Is mountain: {}\n---", result);
    }
}
