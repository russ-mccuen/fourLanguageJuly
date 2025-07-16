import java.util.Scanner;

public class PrimeFinder {

    public static boolean isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    public static void printPrimesUpTo(int n) {
        for (int i = 2; i <= n; i++) {
            if (isPrime(i)) {
                System.out.print(i + " ");
            }
        }
        System.out.println(); // New line after printing all primes
    }

    public static int getUserInput() {
        Scanner scanner = new Scanner(System.in);
        int num;
        while (true) {
            System.out.print("Enter a positive whole number: ");
            String input = scanner.nextLine();
            try {
                num = Integer.parseInt(input);
                if (num >= 2) {
                    break;
                } else {
                    System.out.println("Please enter a number 2 or greater.");
                }
            } catch (NumberFormatException e) {
                System.out.println("Please enter a valid number.");
            }
        }
        scanner.close();
        return num;
    }

    public static void main(String[] args) {
        int userNum = getUserInput();
        System.out.println("Prime numbers up to " + userNum + ":");
        printPrimesUpTo(userNum);
    }
}
