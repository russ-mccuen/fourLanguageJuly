def compress_and_merge(row):
    # Remove zeros
    row = [n for n in row if n != 0]
    
    # Merge adjacent equal numbers
    i = 0
    merged = []
    while i < len(row):
        if i + 1 < len(row) and row[i] == row[i + 1]:
            merged.append(row[i] * 2)
            i += 2
        else:
            merged.append(row[i])
            i += 1
    
    # Pad with zeros
    merged += [0] * (4 - len(merged))
    return merged

def move_left(grid):
    return [compress_and_merge(row) for row in grid]

def print_board(title, grid):
    print(title)
    for row in grid:
        print(row)

def main():
    board = [
        [2, 0, 2, 4],
        [0, 4, 4, 8],
        [2, 2, 2, 2],
        [0, 0, 0, 2]
    ]
    print_board("Before:", board)
    moved = move_left(board)
    print_board("\nAfter:", moved)

if __name__ == "__main__":
    main()
