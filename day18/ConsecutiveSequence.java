import java.util.*;

public class Day18 {
    public static int longestConsecutive(int[] nums) {
        Set<Integer> numSet = new HashSet<>();
        for (int num : nums) numSet.add(num);

        int longest = 0;
        for (int num : numSet) {
            if (!numSet.contains(num - 1)) {
                int current = num;
                int streak = 1;

                while (numSet.contains(current + 1)) {
                    current++;
                    streak++;
                }

                longest = Math.max(longest, streak);
            }
        }
        return longest;
    }

    public static void main(String[] args) {
        Random rand = new Random();
        int length = rand.nextInt(21) + 10; // length 10 to 30
        Set<Integer> numSet = new HashSet<>();
        while (numSet.size() < length) {
            numSet.add(rand.nextInt(100));
        }
        int[] nums = numSet.stream().mapToInt(Integer::intValue).toArray();

        System.out.println("Input: " + Arrays.toString(nums));
        System.out.println("Longest consecutive sequence length: " + longestConsecutive(nums));
    }
}
