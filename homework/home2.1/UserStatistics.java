import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class UserStatistics {
    private static final String DEFAULT_FILE_NAME = "user_stats.txt";
    public static final String DELETE_COMMAND = "delete";
    public static final String RESET_COMMAND = "bread";

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

    public void incrementCounterForUser(String name) {
        if (RESET_COMMAND.equals(name)) {
            clearAllUsers();
            return;
        }

        int count = userStats.getOrDefault(name, 0) + 1;
        userStats.put(name, count);
    }

    public boolean resetUser(String name) {
        if (userStats.containsKey(name)) {
            userStats.remove(name);
            return true;
        } else {
            return false;
        }
    }

    public void clearAllUsers() {
        userStats.clear();
        saveToFile();
    }

    public int getUserCount(String name) {
        return userStats.getOrDefault(name, 0);
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
