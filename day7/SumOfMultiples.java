import java.util.Scanner;

public class SumOfMultiples {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("Please enter a positive whole number: ");
            String userInput = scanner.nextLine();

            try {
                int userNum = Integer.parseInt(userInput);

                if (userNum <= 1) {
                    System.out.println("\nPlease only enter a positive whole number greater than 1.\n");
                    continue;
                }

                int sum = 0;
                for (int i = 1; i < userNum; i++) {
                    if (i % 3 == 0 || i % 5 == 0) {
                        sum += i;
                    }
                }

                System.out.println("The sum of multiples of 3 or 5 below " + userNum + " is " + sum + ".");
                break;

            } catch (NumberFormatException e) {
                System.out.println("\nPlease only enter a positive whole number.\n");
            }
        }

        scanner.close();
    }
}
