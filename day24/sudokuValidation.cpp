#include <iostream>
#include <vector>
#include <unordered_set>

using Board = std::vector<std::vector<char>>;

bool isValidSudoku(const Board& board) {
    // Check rows and columns
    for (int i = 0; i < 9; ++i) {
        std::unordered_set<char> row, col;
        for (int j = 0; j < 9; ++j) {
            char r = board[i][j];
            char c = board[j][i];
            if (r != '.' && !row.insert(r).second) return false;
            if (c != '.' && !col.insert(c).second) return false;
        }
    }

    // Check 3x3 boxes
    for (int boxRow = 0; boxRow < 9; boxRow += 3) {
        for (int boxCol = 0; boxCol < 9; boxCol += 3) {
            std::unordered_set<char> box;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    char val = board[boxRow + i][boxCol + j];
                    if (val != '.' && !box.insert(val).second) return false;
                }
            }
        }
    }

    return true;
}

void printBoard(const Board& board) {
    for (const auto& row : board) {
        for (char c : row) std::cout << c << ' ';
        std::cout << '\n';
    }
}

int main() {
    Board valid1 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Board valid2 = {
        {'8','.','.','.','.','.','.','.','.'},
        {'.','.','3','6','.','.','.','.','.'},
        {'.','7','.','.','9','.','2','.','.'},
        {'.','5','.','.','.','7','.','.','.'},
        {'.','.','.','.','4','5','7','.','.'},
        {'.','.','.','1','.','.','.','3','.'},
        {'.','.','1','.','.','.','.','6','8'},
        {'.','.','8','5','.','.','.','1','.'},
        {'.','9','.','.','.','.','4','.','.'}
    };

    Board invalidRow = {
        {'5','3','.','.','7','.','.','.','5'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Board invalidBox = {
        {'5','3','6','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    std::vector<std::pair<std::string, Board>> tests = {
        {"Valid Board 1", valid1},
        {"Valid Board 2", valid2},
        {"Invalid Board (Row)", invalidRow},
        {"Invalid Board (Box)", invalidBox}
    };

    for (const auto& [name, board] : tests) {
        std::cout << name << ":\n";
        printBoard(board);
        std::cout << "Is valid: " << (isValidSudoku(board) ? "true" : "false") << "\n";
        std::cout << "----------------------------------------\n";
    }

    return 0;
}
