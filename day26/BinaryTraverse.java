import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class BinaryTraverse {

    public static List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) return result;

        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            int size = queue.size();
            List<Integer> level = new ArrayList<>();
            while (size-- > 0) {
                TreeNode node = queue.poll();
                level.add(node.val);
                if (node.left != null) queue.offer(node.left);
                if (node.right != null) queue.offer(node.right);
            }
            result.add(level);
        }

        return result;
    }

    public static List<Integer> treeToList(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;

        Queue<TreeNode> queue = new LinkedList<>(); // allows nulls
        queue.offer(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node != null) {
                result.add(node.val);
                queue.offer(node.left);
                queue.offer(node.right);
            } else {
                result.add(null);
            }
        }

        // Trim trailing nulls
        int i = result.size() - 1;
        while (i >= 0 && result.get(i) == null) {
            result.remove(i--);
        }

        return result;
    }

    public static TreeNode generateRandomTree(int n) {
        if (n == 0) return null;

        Random rand = new Random();
        TreeNode[] nodes = new TreeNode[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new TreeNode(rand.nextInt(100));
        }

        for (int i = 0; i < n; i++) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < n) nodes[i].left = nodes[left];
            if (right < n) nodes[i].right = nodes[right];
        }

        return nodes[0];
    }

    public static void main(String[] args) {
        int n = new Random().nextInt(6) + 5; // 5–10 nodes
        TreeNode root = generateRandomTree(n);

        System.out.println("Generated binary tree with " + n + " nodes:");
        System.out.println("Tree as level-order list:");
        System.out.println(treeToList(root));
        System.out.println("\nLevel order traversal (grouped by level):");
        System.out.println(levelOrder(root));
    }
}
