import java.util.Scanner;

public class EvenOdd {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true){
            System.out.print("Enter a whole number (no decimals): ");

            try{
                int user_input = scanner.nextInt();

                if (user_input % 2 == 0){
                    System.out.println("The number is even.");
                } else {
                    System.out.println("The number is odd.");
                }
                break;
              
            } catch (Exception e) {
                System.out.println("Please enter a whole number.");
                scanner.nextLine();
            }
        }
        scanner.close();
    }
}
