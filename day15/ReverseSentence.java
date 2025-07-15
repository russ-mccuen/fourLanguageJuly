import java.util.Scanner;

public class ReverseSentence {

    public static String reverseSentence(Scanner scanner) {
        while (true) {
            System.out.println("\nPlease type a sentence and I will reverse the word order:");
            String input = scanner.nextLine().trim();

            if (input.isEmpty()) {
                System.out.println("\nPlease type at least one character.\n");
                continue;
            }

            String[] words = input.split("\\s+");
            StringBuilder reversed = new StringBuilder();

            for (int i = words.length - 1; i >= 0; i--) {
                reversed.append(words[i]);
                if (i > 0) reversed.append(" ");
            }

            return reversed.toString();
        }
    }

    public static void printReversed(String reversed) {
        System.out.println(reversed);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String reversed = reverseSentence(scanner);
        printReversed(reversed);
        scanner.close();
    }
}
