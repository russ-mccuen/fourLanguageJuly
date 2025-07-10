import java.util.Scanner;

public class CountVowels {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a word or words and I will count the number of vowels: ");
        String input = scanner.nextLine().toLowerCase();

        int vowelCount = 0;
        for (char c : input.toCharArray()) {
            if ("aeiou".indexOf(c) != -1) {
                vowelCount++;
            }
        }

        System.out.println("The number of vowels in your input is " + vowelCount + " (not including y).");
        scanner.close();
    }
}
