#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int SIZE = 4;

using Board = std::vector<std::vector<int>>;

Board generateBoard() {
    return {
        {2, 0, 2, 4},
        {0, 4, 4, 8},
        {2, 2, 2, 2},
        {0, 0, 0, 2}
    };
}

Board moveLeft(const Board& board) {
    Board newBoard(SIZE, std::vector<int>(SIZE, 0));

    for (int row = 0; row < SIZE; ++row) {
        std::vector<int> temp;

        // Slide all non-zero tiles to the left
        for (int col = 0; col < SIZE; ++col) {
            if (board[row][col] != 0) {
                temp.push_back(board[row][col]);
            }
        }

        // Merge adjacent equal tiles
        std::vector<int> merged;
        for (size_t i = 0; i < temp.size(); ++i) {
            if (i + 1 < temp.size() && temp[i] == temp[i + 1]) {
                merged.push_back(temp[i] * 2);
                ++i; // skip the next
            } else {
                merged.push_back(temp[i]);
            }
        }

        // Fill rest with 0s
        while (merged.size() < SIZE) {
            merged.push_back(0);
        }

        newBoard[row] = merged;
    }

    return newBoard;
}

void printBoard(const std::string& label, const Board& board) {
    std::cout << label << "\n";
    for (const auto& row : board) {
        std::cout << "[";
        for (size_t i = 0; i < row.size(); ++i) {
            std::cout << row[i];
            if (i != row.size() - 1) std::cout << ", ";
        }
        std::cout << "]\n";
    }
    std::cout << "\n";
}

int main() {
    Board before = generateBoard();
    Board after = moveLeft(before);

    printBoard("Before:", before);
    printBoard("After:", after);

    return 0;
}
