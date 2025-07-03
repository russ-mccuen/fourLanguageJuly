import java.util.Scanner;

public class FizzBuzz {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("Please enter a number: ");

            try {
                int numCheck = scanner.nextInt();

                for (int i = 1; i <= numCheck; i++) {
                    if (i % 15 == 0) {
                        System.out.println("Fizzbuzz");
                    } else if (i % 3 == 0) {
                        System.out.println("Fizz");
                    } else if (i % 5 == 0) {
                        System.out.println("Buzz");
                    } else {
                        System.out.println(i);
                    }
                }
                break;
            } catch (Exception e) {
                System.out.println("Please only enter a number.");
                scanner.nextLine(); // clear bad input
            }
        }

        scanner.close();
    }
}
