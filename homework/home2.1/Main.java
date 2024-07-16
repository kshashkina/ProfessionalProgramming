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

        String message = "";

        if (isDeleteCmd) {
            if (additionalCmd.equals(UserStatistics.DELETE_COMMAND)) {
                message = resetUserMessage(stats, name);
            } else if (additionalCmd.equals(UserStatistics.RESET_COMMAND)) {
                message = clearAllUsersMessage(stats);
            } else {
                message = "Error: Invalid command.";
            }
        } else {
            message = incrementCounterMessage(stats, name);
        }

        System.out.println(message);

        // Ensure to close the statistics file after use
        stats.close();
    }

    private static String incrementCounterMessage(UserStatistics stats, String name) {
        stats.incrementCounterForUser(name);
        int count = stats.getUserCount(name);
        if (count == 1) {
            return String.format("Welcome, %s!", name);
        } else {
            return String.format("Hello again(%d), %s!", count, name);
        }
    }


    private static String resetUserMessage(UserStatistics stats, String name) {
        if (stats.resetUser(name)) {
            return String.format("Statistics for %s have been reset.", name);
        } else {
            return String.format("No statistics to reset for %s.", name);
        }
    }

    private static String clearAllUsersMessage(UserStatistics stats) {
        stats.clearAllUsers();
        return "All history has been exterminated.";
    }
}
