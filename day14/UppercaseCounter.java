import java.util.Scanner;

public class UppercaseCounter {

    public static void main(String[] args) {
        int upperCount = getUpperCount();
        printUpperCount(upperCount);
    }

    public static int getUpperCount() {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("Please type a sentence and I will tell you how many uppercase letters it has:");
            String input = scanner.nextLine();

            if (input.trim().isEmpty()) {
                System.out.println("\nPlease type at least one character.\n");
                continue;
            }

            int count = 0;
            for (char c : input.toCharArray()) {
                if (Character.isUpperCase(c)) {
                    count++;
                }
            }
            return count;
        }
    }

    public static void printUpperCount(int count) {
        System.out.println("The number of uppercase letters is " + count + ".");
    }
}
