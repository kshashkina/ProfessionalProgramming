import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input coefficients
        System.out.print("Enter coefficient a: ");
        while (!scanner.hasNextDouble()) {
            System.out.print("Invalid input. Enter coefficient a: ");
            scanner.next();
        }
        double a = scanner.nextDouble();

        if (a == 0) {
            System.out.println("Coefficient 'a' must not be zero, as this would not be a quadratic equation.");
            return;
        }

        System.out.print("Enter coefficient b: ");
        while (!scanner.hasNextDouble()) {
            System.out.print("Invalid input. Enter coefficient b: ");
            scanner.next();
        }
        double b = scanner.nextDouble();

        System.out.print("Enter coefficient c: ");
        while (!scanner.hasNextDouble()) {
            System.out.print("Invalid input. Enter coefficient c: ");
            scanner.next();
        }
        double c = scanner.nextDouble();

        // Calculate the determinant
        double determinant = b * b - 4 * a * c;
        System.out.println("Determinant: " + determinant);

        // Determine and display roots
        if (determinant > 0) {
            double root1 = (-b + Math.sqrt(determinant)) / (2 * a);
            double root2 = (-b - Math.sqrt(determinant)) / (2 * a);
            System.out.println("The equation has two real roots: root1 = " + root1 + ", root2 = " + root2);
        } else if (determinant == 0) {
            double root = -b / (2 * a);
            System.out.println("The equation has one real root: root = " + root);
        } else {
            System.out.println("The equation does not have real roots.");
        }
    }
}
