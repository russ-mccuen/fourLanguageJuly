import java.util.*;

public class MergeIntervals {

    public static int[][] merge(int[][] intervals) {
        if (intervals.length == 0) return new int[0][];
        
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        List<int[]> merged = new ArrayList<>();
        merged.add(intervals[0]);

        for (int i = 1; i < intervals.length; i++) {
            int[] last = merged.get(merged.size() - 1);
            int[] current = intervals[i];

            if (current[0] <= last[1]) {
                last[1] = Math.max(last[1], current[1]); // merge
            } else {
                merged.add(current);
            }
        }

        return merged.toArray(new int[merged.size()][]);
    }

    public static int[][] generateTestCase() {
        Random rand = new Random();
        int n = rand.nextInt(6) + 5; // 5–10 intervals
        int[][] intervals = new int[n][2];
        for (int i = 0; i < n; i++) {
            int start = rand.nextInt(21); // 0–20
            int end = start + rand.nextInt(10) + 1;
            intervals[i][0] = start;
            intervals[i][1] = end;
        }
        // Shuffle the array
        for (int i = 0; i < n; i++) {
            int j = rand.nextInt(n);
            int[] tmp = intervals[i];
            intervals[i] = intervals[j];
            intervals[j] = tmp;
        }
        return intervals;
    }

    public static void main(String[] args) {
        int[][] intervals = generateTestCase();
        System.out.print("Input: ");
        for (int[] interval : intervals)
            System.out.print(Arrays.toString(interval) + " ");
        System.out.println();

        int[][] result = merge(intervals);
        System.out.print("Merged: ");
        for (int[] interval : result)
            System.out.print(Arrays.toString(interval) + " ");
        System.out.println();
    }
}
