import java.util.Scanner;

public class CharacterCount {

    public static int countCharacter(String input, char target) {
        int count = 0;
        for (char c : input.toCharArray()) {
            if (c == target) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String userInput = "";
        String charInput = "";

        // Validate sentence input
        while (userInput.trim().isEmpty()) {
            System.out.print("Enter a sentence or phrase: ");
            userInput = scanner.nextLine();
            if (userInput.trim().isEmpty()) {
                System.out.println("Please enter at least one character.");
            }
        }

        // Validate single character input
        while (charInput.length() != 1) {
            System.out.print("Enter a single character to count: ");
            charInput = scanner.nextLine();
            if (charInput.length() != 1) {
                System.out.println("Please enter exactly one character.");
            }
        }

        char targetChar = charInput.charAt(0);
        int result = countCharacter(userInput, targetChar);
        System.out.println("The character '" + targetChar + "' appears " + result + " time(s).");

        scanner.close();
    }
}
