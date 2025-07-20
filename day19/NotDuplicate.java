import java.util.*;

public class NotDuplicate {

    public static int singleNumber(int[] nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num; // XOR cancels out pairs
        }
        return result;
    }

    public static void main(String[] args) {
        Random rand = new Random();
        int length = rand.nextInt(11) + 10; // 10 to 20 unique values

        // Generate unique values using a Set
        Set<Integer> uniqueValsSet = new HashSet<>();
        while (uniqueValsSet.size() < length) {
            uniqueValsSet.add(rand.nextInt(100));
        }

        List<Integer> uniqueVals = new ArrayList<>(uniqueValsSet);
        int single = uniqueVals.remove(uniqueVals.size() - 1); // value that appears once

        List<Integer> numsList = new ArrayList<>();
        for (int val : uniqueVals) {
            numsList.add(val);
            numsList.add(val); // add each remaining value twice
        }
        numsList.add(single); // add the one that appears once
        Collections.shuffle(numsList);

        int[] nums = numsList.stream().mapToInt(Integer::intValue).toArray();

        System.out.println("Input: " + Arrays.toString(nums));
        System.out.println("Expected single number: " + single);
        System.out.println("Computed single number: " + singleNumber(nums));
    }
}
