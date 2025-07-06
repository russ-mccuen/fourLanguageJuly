import java.util.Scanner;

public class Factorial {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println(); // Blank line before
            System.out.print("Please enter a positive whole number: ");
            String userInput = scanner.nextLine();
            // No extra println() here

            try {
                int userNum = Integer.parseInt(userInput);

                if (userNum < 1) {
                    System.out.println();
                    System.out.println("Please only enter a positive whole number.");
                    continue;
                }

                long factorial = 1;
                for (int i = 1; i <= userNum; i++) {
                    factorial *= i;
                }

                System.out.println("\nThe factorial of " + userNum + " is " + factorial + ".");
                break;

            } catch (NumberFormatException e) {
                System.out.println();
                System.out.println("Please only enter a positive whole number.");
            }
        }

        scanner.close();
    }
}
