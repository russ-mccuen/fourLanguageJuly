def is_valid_sudoku(board):
    def is_valid_group(values):
        nums = [v for v in values if v != '.']
        return len(nums) == len(set(nums))

    # Check rows
    for row in board:
        if not is_valid_group(row):
            return False

    # Check columns
    for col in zip(*board):
        if not is_valid_group(col):
            return False

    # Check 3x3 boxes
    for box_row in range(0, 9, 3):
        for box_col in range(0, 9, 3):
            box = [
                board[r][c]
                for r in range(box_row, box_row + 3)
                for c in range(box_col, box_col + 3)
            ]
            if not is_valid_group(box):
                return False

    return True

def print_board(board):
    for row in board:
        print(" ".join(row))
    print()

def main():
    valid_board_1 = [
        ["5","3",".",".","7",".",".",".","."],
        ["6",".",".","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9",".",".","5"],
        [".",".",".",".","8",".",".","7","9"]
    ]

    valid_board_2 = [
        ["8",".",".",".",".",".",".",".","."],
        [".",".","3","6",".",".",".",".","."],
        [".","7",".",".","9",".","2",".","."],
        [".","5",".",".",".","7",".",".","."],
        [".",".",".",".","4","5","7",".","."],
        [".",".",".","1",".",".",".","3","."],
        [".",".","1",".",".",".",".","6","8"],
        [".",".","8","5",".",".",".","1","."],
        [".","9",".",".",".",".","4",".","."]
    ]

    invalid_board_row = [  # Duplicate '5' in first row
        ["5","3",".",".","7",".",".",".","5"],
        ["6",".",".","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9",".",".","5"],
        [".",".",".",".","8",".",".","7","9"]
    ]

    invalid_board_box = [  # Duplicate '6' in top-left 3x3 box
        ["5","3","6",".","7",".",".",".","."],
        ["6",".",".","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9",".",".","5"],
        [".",".",".",".","8",".",".","7","9"]
    ]

    test_cases = [
        ("Valid Board 1", valid_board_1),
        ("Valid Board 2", valid_board_2),
        ("Invalid Board (Row)", invalid_board_row),
        ("Invalid Board (Box)", invalid_board_box),
    ]

    for name, board in test_cases:
        print(f"{name}:")
        print_board(board)
        print("Is valid:", is_valid_sudoku(board))
        print("-" * 40)

if __name__ == "__main__":
    main()
