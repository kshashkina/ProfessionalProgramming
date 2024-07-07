public class Main {
    public static void main(String[] args) {
        if (args.length < 1 || args.length > 2) {
            System.err.println("Error: Invalid number of arguments.");
            System.exit(1);
        }

        UserStatistics stats = new UserStatistics();

        String name = args[0];
        boolean isDeleteCmd = (args.length == 2);
        String additionalCmd = isDeleteCmd ? args[1] : "";

        if (isDeleteCmd && !additionalCmd.equals(UserStatistics.DELETE_COMMAND)) {
            System.err.println("Error: Invalid command.");
            System.exit(1);
        }

        StringBuilder message = new StringBuilder();
        if (!isDeleteCmd) {
            stats.incrementCounterForUser(name, message);
        } else {
            stats.resetUser(name, message);
        }
        System.out.println(message.toString());
    }
}
