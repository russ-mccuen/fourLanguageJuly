import java.util.*;

public class FindMissing {

    public static int missingNumber(int[] nums) {
        int n = nums.length;
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;
        for (int num : nums) actualSum += num;
        return expectedSum - actualSum;
    }

    public static void main(String[] args) {
        Random rand = new Random();
        int n = rand.nextInt(21) + 10; // n between 10 and 30
        List<Integer> full = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            full.add(i);
        }

        int missing = full.remove(rand.nextInt(full.size())); // remove one random number
        Collections.shuffle(full);
        int[] nums = full.stream().mapToInt(Integer::intValue).toArray();

        System.out.println("Input: " + Arrays.toString(nums));
        System.out.println("Expected missing number: " + missing);
        System.out.println("Computed missing number: " + missingNumber(nums));
    }
}
