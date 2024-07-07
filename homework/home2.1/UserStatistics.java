import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class UserStatistics {
    private static final String DEFAULT_FILE_NAME = "user_stats.txt";
    private static final String RESET_COMMAND = "bread";
    public static final String DELETE_COMMAND = "delete";

    private Map<String, Integer> userStats;
    private String fileName;

    public UserStatistics(String statisticsFilePath) {
        this.fileName = statisticsFilePath;
        this.userStats = new HashMap<>();
        loadFromFile();
    }

    public UserStatistics() {
            this(DEFAULT_FILE_NAME);
    }

    public void close() {
        saveToFile();
    }

    public boolean incrementCounterForUser(String name, StringBuilder message) {
        if (name.equals(RESET_COMMAND)) {
            userStats.clear();
            saveToFile();
            message.append("All history has been exterminated.");
            return true;
        }

        if (!userStats.containsKey(name)) {
            userStats.put(name, 1);
            message.append(String.format("Welcome, %s!", name));
            return true;
        } else {
            int count = userStats.get(name) + 1;
            userStats.put(name, count);
            message.append(String.format("Hello again(%d), %s!", count, name));
            return true;
        }
    }

    public boolean resetUser(String name, StringBuilder message) {
        if (userStats.containsKey(name)) {
            userStats.remove(name);
            message.append(String.format("Statistics for %s have been reset.", name));
            return true;
        } else {
            message.append(String.format("No statistics to reset for %s.", name));
            return false;
        }
    }

    private void loadFromFile() {
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(" ");
                if (parts.length == 2) {
                    String name = parts[0];
                    int count = Integer.parseInt(parts[1]);
                    userStats.put(name, count);
                }
            }
        } catch (IOException e) {
            System.err.println("Error reading from file: " + e.getMessage());
        }
    }

    private void saveToFile() {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(fileName))) {
            for (Map.Entry<String, Integer> entry : userStats.entrySet()) {
                bw.write(entry.getKey() + " " + entry.getValue() + "\n");
            }
        } catch (IOException e) {
            System.err.println("Error writing to file: " + e.getMessage());
        }
    }
}
