import java.util.Arrays;

// Can't start a Java file name with a digit
public class Validator2048 {

    public static void main(String[] args) {
        int[][] board = {
            {2, 0, 2, 4},
            {0, 4, 4, 8},
            {2, 2, 2, 2},
            {0, 0, 0, 2}
        };

        System.out.println("Before:");
        printBoard(board);

        int[][] moved = moveLeft(board);

        System.out.println("\nAfter:");
        printBoard(moved);
    }

    public static int[][] moveLeft(int[][] board) {
        int[][] result = new int[board.length][board[0].length];
        for (int r = 0; r < board.length; r++) {
            result[r] = compressAndMerge(board[r]);
        }
        return result;
    }

    public static int[] compressAndMerge(int[] row) {
        int[] nonZero = Arrays.stream(row).filter(val -> val != 0).toArray();
        int[] merged = new int[row.length];
        int i = 0, j = 0;

        while (i < nonZero.length) {
            if (i + 1 < nonZero.length && nonZero[i] == nonZero[i + 1]) {
                merged[j++] = nonZero[i] * 2;
                i += 2;
            } else {
                merged[j++] = nonZero[i++];
            }
        }
        return merged;
    }

    public static void printBoard(int[][] board) {
        for (int[] row : board) {
            System.out.println(Arrays.toString(row));
        }
    }
}
