Write a program that checks whether a given 9×9 Sudoku board is valid. The board may be partially filled, but all non-empty cells must follow these rules:

  Each row must contain the digits 1–9 at most once.

  Each column must contain the digits 1–9 at most once.

  Each 3×3 sub-box must contain the digits 1–9 at most once.

The board is represented as a 2D array of characters ('1' to '9' and '.' for empty).

Input:

    Your program should validate 4 total boards:

        2 valid boards

        2 invalid boards (one with a duplicate in a row/column, one in a 3×3 box)

Output:

For each board:

    Print the board

    Print whether it's valid (true) or not (false)
