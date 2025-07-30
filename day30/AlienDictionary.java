import java.util.*; 

public class AlienDictionary {

    public static String alienOrder(String[] words) {
        // Step 1: Create data structures
        Map<Character, Set<Character>> graph = new HashMap<>();
        Map<Character, Integer> inDegree = new HashMap<>();

        // Initialize inDegree for all unique characters
        for (String word : words) {
            for (char c : word.toCharArray()) {
                inDegree.putIfAbsent(c, 0);
            }
        }

        System.out.println("Initial in-degree map: " + inDegree);

        // Step 2: Build graph by comparing adjacent words
        for (int i = 0; i < words.length - 1; i++) {
            String first = words[i];
            String second = words[i + 1];
            int len = Math.min(first.length(), second.length());

            if (first.length() > second.length() && first.startsWith(second)) {
                // Invalid case: prefix problem
                return "";
            }

            for (int j = 0; j < len; j++) {
                char a = first.charAt(j);
                char b = second.charAt(j);
                if (a != b) {
                    graph.putIfAbsent(a, new HashSet<>());
                    if (!graph.get(a).contains(b)) {
                        graph.get(a).add(b);
                        inDegree.put(b, inDegree.get(b) + 1);
                    }
                    break;
                }
            }
        }

        // Debug print of graph
        System.out.println("Graph (edges):");
        for (char key : graph.keySet()) {
            System.out.println("  " + key + " → " + graph.get(key));
        }
        System.out.println("Updated in-degree map: " + inDegree);

        // Step 3: Topological sort using BFS
        Queue<Character> queue = new LinkedList<>();
        for (char c : inDegree.keySet()) {
            if (inDegree.get(c) == 0) {
                queue.offer(c);
            }
        }

        StringBuilder result = new StringBuilder();
        System.out.println("Starting BFS with queue: " + queue);

        while (!queue.isEmpty()) {
            char current = queue.poll();
            result.append(current);
            System.out.println("Visiting: " + current);

            if (graph.containsKey(current)) {
                for (char neighbor : graph.get(current)) {
                    inDegree.put(neighbor, inDegree.get(neighbor) - 1);
                    if (inDegree.get(neighbor) == 0) {
                        queue.offer(neighbor);
                    }
                }
            }
        }

        // If the result does not include all characters, there was a cycle
        if (result.length() < inDegree.size()) {
            return "";
        }

        return result.toString();
    }

    public static void main(String[] args) {
        String[] words = {"wrt", "wrf", "er", "ett", "rftt"};
        System.out.println("Input words: " + Arrays.toString(words));
        System.out.println("Alien dictionary order: " + alienOrder(words));
    }
}
