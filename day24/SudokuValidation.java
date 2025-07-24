import java.util.*;

public class SudokuValidation {

    public static boolean isValidSudoku(char[][] board) {
        // Check rows and columns
        for (int i = 0; i < 9; i++) {
            Set<Character> row = new HashSet<>();
            Set<Character> col = new HashSet<>();
            for (int j = 0; j < 9; j++) {
                char r = board[i][j];
                char c = board[j][i];
                if (r != '.' && !row.add(r)) return false;
                if (c != '.' && !col.add(c)) return false;
            }
        }

        // Check 3x3 boxes
        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                Set<Character> box = new HashSet<>();
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char val = board[boxRow + i][boxCol + j];
                        if (val != '.' && !box.add(val)) return false;
                    }
                }
            }
        }

        return true;
    }

    public static void printBoard(char[][] board) {
        for (char[] row : board) {
            for (char c : row) System.out.print(c + " ");
            System.out.println();
        }
    }

    public static void main(String[] args) {
        char[][] valid1 = {
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

        char[][] valid2 = {
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

        char[][] invalidRow = {
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

        char[][] invalidBox = {
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

        Object[][] testCases = {
            {"Valid Board 1", valid1},
            {"Valid Board 2", valid2},
            {"Invalid Board (Row)", invalidRow},
            {"Invalid Board (Box)", invalidBox}
        };

        for (Object[] test : testCases) {
            String name = (String) test[0];
            char[][] board = (char[][]) test[1];
            System.out.println(name + ":");
            printBoard(board);
            System.out.println("Is valid: " + isValidSudoku(board));
            System.out.println("----------------------------------------");
        }
    }
}
