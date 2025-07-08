import java.util.Scanner;

public class PrimeCheck {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("Please enter a number and I will tell you if it is prime: ");
            String input = scanner.nextLine();

            try {
                int userNum = Integer.parseInt(input);

                if (isPrime(userNum)) {
                    System.out.println(userNum + " is a prime number.");
                } else {
                    System.out.println(userNum + " is not a prime number.");
                }
                break;

            } catch (NumberFormatException e) {
                System.out.println("\nPlease only enter a number.\n");
            }
        }

        scanner.close();
    }

    public static boolean isPrime(int num) {
        if (num <= 1) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;

        for (int i = 3; i <= Math.sqrt(num); i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    }
}
