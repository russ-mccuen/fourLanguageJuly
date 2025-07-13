import java.util.Scanner;

public class MultiplicationTable {
    public static void main(String[] args) {
        printMultiplicationTable();
    }

    public static void printMultiplicationTable() {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("Please enter a number and I will print\nthe multiplication table, to 10, for that number: ");
            String input = scanner.nextLine();
            System.out.println(); // extra line after prompt

            try {
                int number = Integer.parseInt(input);
                for (int i = 1; i <= 10; i++) {
                    System.out.println(number + " x " + i + " = " + (number * i));
                }
                break;
            } catch (NumberFormatException e) {
                System.out.println("\nPlease enter a number.\n");
            }
        }

        scanner.close();
    }
}
