public class MountainArrayChecker {
    public static boolean isMountainArray(int[] arr) {
        System.out.print("Input array: ");
        for (int val : arr) System.out.print(val + " ");
        System.out.println();

        int n = arr.length;
        if (n < 3) return false;

        int i = 0;

        // Ascend
        while (i + 1 < n && arr[i] < arr[i + 1]) i++;

        // Peak can't be first or last
        if (i == 0 || i == n - 1) return false;

        // Descend
        while (i + 1 < n && arr[i] > arr[i + 1]) i++;

        return i == n - 1;
    }

    public static void main(String[] args) {
        int[][] testCases = {
            {0, 3, 2, 1},
            {2, 1},
            {3, 5, 5},
            {0, 1, 2, 3, 2, 1, 0}
        };

        for (int[] test : testCases) {
            boolean result = isMountainArray(test);
            System.out.println("Is mountain: " + result);
            System.out.println("---");
        }
    }
}
