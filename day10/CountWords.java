import java.util.Scanner;
import java.util.HashMap;

public class CountWords {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Prompt the user to enter a sentence
        System.out.print("Enter a sentence: ");
        String input = scanner.nextLine().toLowerCase(); // convert to lowercase to ignore case

        // Split the sentence into individual words by spaces
        String[] words = input.split("\\s+"); // "\\s+" matches one or more spaces

        // Create a HashMap to store each word and its count
        HashMap<String, Integer> wordCounts = new HashMap<>();

        // Loop through each word
        for (String word : words) {
            // If the word is already in the map, increment its count
            // Otherwise, add it with a count of 1
            wordCounts.put(word, wordCounts.getOrDefault(word, 0) + 1);
        }

        // Print out each word and how many times it appeared
        for (String word : wordCounts.keySet()) {
            System.out.println(word + ": " + wordCounts.get(word));
        }

        scanner.close(); // Close the scanner when done
    }
}
