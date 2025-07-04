import java.util.Scanner;

public class Reverse {
    public static void main(String[] args) {
        System.out.print("Please enter a word: ");
        String word = new Scanner(System.in).nextLine();
        System.out.println(new StringBuilder(word).reverse());
        scanner.close();
    }
}
