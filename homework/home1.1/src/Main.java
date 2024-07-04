import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        double[] coefficients = readCoefficients(scanner);
        scanner.close();

        if (coefficients == null) {
            System.out.println("Invalid input. Please enter valid coefficients.");
            return;
        }

        double a = coefficients[0];
        double b = coefficients[1];
        double c = coefficients[2];

        double[] roots = calculateRoots(a, b, c);

        if (roots.length == 0) {
            System.out.println("The equation does not have real roots.");
        } else if (roots.length == 1) {
            System.out.println("The equation has one real root: root = " + roots[0]);
        } else {
            System.out.println("The equation has two real roots: root1 = " + roots[0] + ", root2 = " + roots[1]);
        }
    }

    private static double[] readCoefficients(Scanner scanner) {
        double[] coefficients = new double[3];

        for (int i = 0; i < 3; i++) {
            System.out.print("Enter coefficient " + (char) ('a' + i) + ": ");
            while (!scanner.hasNextDouble()) {
                System.out.print("Invalid input. Enter coefficient " + (char) ('a' + i) + ": ");
                scanner.next();
            }
            coefficients[i] = scanner.nextDouble();
        }

        return coefficients[0] == 0 ? null : coefficients;
    }

    private static double[] calculateRoots(double a, double b, double c) {
        double[] roots = new double[0];
        double determinant = b * b - 4 * a * c;

        if (determinant > 0) {
            roots = new double[2];
            roots[0] = (-b + Math.sqrt(determinant)) / (2 * a);
            roots[1] = (-b - Math.sqrt(determinant)) / (2 * a);
        } else if (determinant == 0) {
            roots = new double[1];
            roots[0] = -b / (2 * a);
        }

        return roots;
    }
}
