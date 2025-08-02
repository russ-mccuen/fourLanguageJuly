fn slide_row_left(row: &[i32]) -> Vec<i32> {
    let tiles: Vec<i32> = row.iter().cloned().filter(|&x| x != 0).collect();
    let mut new_row = Vec::new();
    let mut skip = false;

    for i in 0..tiles.len() {
        if skip {
            skip = false;
            continue;
        }
        if i + 1 < tiles.len() && tiles[i] == tiles[i + 1] {
            new_row.push(tiles[i] * 2);
            skip = true;
        } else {
            new_row.push(tiles[i]);
        }
    }

    while new_row.len() < 4 {
        new_row.push(0);
    }

    new_row
}

fn print_board(board: &[Vec<i32>]) {
    for row in board {
        println!("{:?}", row);
    }
}

fn main() {
    let board = vec![
        vec![2, 0, 2, 4],
        vec![0, 4, 4, 8],
        vec![2, 2, 2, 2],
        vec![0, 0, 0, 2],
    ];

    println!("Before:");
    print_board(&board);

    let new_board: Vec<Vec<i32>> = board.iter().map(|row| slide_row_left(row)).collect();

    println!("\nAfter:");
    print_board(&new_board);
}
