import java.util.Scanner;

public class NumSum {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true){
            System.out.print("Enter a positive integer: ");

            try {
                int user_input = scanner.nextInt();

                if (user_input < 0) {
                    System.out.println("Please enter a positive whole number.");
                    scanner.nextLine();
                    continue;
                }

                int sum = 0;
                int temp = user_input;

                while (temp > 0) {
                    sum += temp % 10;  // Add last digit
                    temp /= 10;        // Remove last digit
                }

                System.out.println("The sum is " + sum);
                break;

            } catch (Exception e) {
                System.out.println("Please enter a positive whole number.");
                scanner.nextLine();
            }
        }
        scanner.close();
    }
}
