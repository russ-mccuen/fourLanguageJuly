import java.util.*;

public class ProductExceptSelf {

    public static int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] output = new int[n];

        // Prefix pass
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            output[i] = prefix;
            prefix *= nums[i];
        }

        // Suffix pass
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            output[i] *= suffix;
            suffix *= nums[i];
        }

        return output;
    }

    public static void main(String[] args) {
        Random rand = new Random();
        int length = rand.nextInt(6) + 5; // length 5 to 10
        int[] nums = new int[length];
        for (int i = 0; i < length; i++) {
            nums[i] = rand.nextInt(10) + 1; // values 1 to 10
        }

        System.out.println("Input: " + Arrays.toString(nums));
        int[] result = productExceptSelf(nums);
        System.out.println("Output: " + Arrays.toString(result));
    }
}
