import java.util.*;

public class WordLadderShuffle {

    public static List<String> wordLadder(String start, String end, List<String> dictionary) {
        System.out.println("Start word: " + start);
        System.out.println("End word: " + end);
        System.out.println("Dictionary: " + dictionary);
        System.out.println();

        Set<String> wordSet = new HashSet<>(dictionary);
        if (!wordSet.contains(end)) {
            System.out.println("End word not in dictionary.");
            return Collections.emptyList();
        }

        Queue<List<String>> queue = new LinkedList<>();
        queue.add(Arrays.asList(start));
        Set<String> visited = new HashSet<>();
        visited.add(start);

        while (!queue.isEmpty()) {
            List<String> path = queue.poll();
            String current = path.get(path.size() - 1);
            System.out.println("Current path: " + path);

            if (current.equals(end)) {
                return path;
            }

            for (int i = 0; i < current.length(); i++) {
                char[] chars = current.toCharArray();
                for (char c = 'a'; c <= 'z'; c++) {
                    chars[i] = c;
                    String next = new String(chars);
                    if (wordSet.contains(next) && !visited.contains(next)) {
                        visited.add(next);
                        List<String> newPath = new ArrayList<>(path);
                        newPath.add(next);
                        queue.add(newPath);
                    }
                }
            }
        }

        System.out.println("No transformation path found.");
        return Collections.emptyList();
    }

    public static void main(String[] args) {
        String start = "hit";
        String end = "cog";
        List<String> dictionary = Arrays.asList("hot", "dot", "dog", "lot", "log", "cog");

        List<String> result = wordLadder(start, end, dictionary);
        System.out.println("\nFinal transformation path:");
        System.out.println(result);
    }
}
