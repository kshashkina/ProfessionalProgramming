import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        UserStatistics stats = new UserStatistics();
        try {
            if (args.length < 1) {
                System.out.println("Error: Please provide a name as an argument.");
                System.exit(1);
            }

            String name = args[0];

            if (args.length == 1) {
                System.out.println(stats.greetUser(name));
            } else if (args.length == 2 && args[1].equals("delete")) {
                System.out.println(stats.resetUser(name));
            } else {
                System.out.println("Error: Invalid arguments.");
                System.exit(1);
            }
        } finally {
            stats.close();
        }
    }
}
