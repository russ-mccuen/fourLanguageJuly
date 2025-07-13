import java.util.Scanner;

public class WordCount {
    public static void main(String[] args) {
        countWords();
    }

    public static void countWords() {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("Please type a sentence (one or more words): ");
            String input = scanner.nextLine().trim();

            if (input.isEmpty()) {
                System.out.println("Input cannot be empty.\n");
                continue;
            }

            String[] words = input.split("\\s+");
            int count = words.length;

            if (count == 1) {
                System.out.println("There is 1 word in your sentence.");
            } else {
                System.out.println("There are " + count + " words in your sentence.");
            }
            break;
        }

        scanner.close();
    }
}
