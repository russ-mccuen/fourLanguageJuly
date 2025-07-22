import java.util.*;

public class KthLargest {

    public static int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int num : nums) {
            minHeap.offer(num);
            if (minHeap.size() > k) {
                minHeap.poll(); // remove smallest in heap
            }
        }
        return minHeap.peek(); // root is the kth largest
    }

    public static void main(String[] args) {
        Random rand = new Random();
        int length = rand.nextInt(21) + 10; // 10 to 30
        int[] nums = new int[length];
        for (int i = 0; i < length; i++) {
            nums[i] = rand.nextInt(101); // 0 to 100
        }

        int k = rand.nextInt(length) + 1; // 1 to length

        System.out.println("Input: " + Arrays.toString(nums));
        System.out.println("k: " + k);
        System.out.println(k + "th largest element: " + findKthLargest(nums, k));
    }
}
