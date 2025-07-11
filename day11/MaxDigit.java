import java.util.Scanner;

public class MaxDigit {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("Enter a number and I will extract the maximum digit: ");
            String input = scanner.nextLine();

            try {
                // Try to parse to ensure input is numeric
                Integer.parseInt(input);

                int maxDigit = 0;
                for (char c : input.toCharArray()) {
                    int digit = Character.getNumericValue(c);
                    if (digit > maxDigit) {
                        maxDigit = digit;
                    }
                }

                System.out.println("The maximum digit is: " + maxDigit);
                break;
            } catch (NumberFormatException e) {
                System.out.println("Please enter only digits.\n");
            }
        }

        scanner.close();
    }
}
