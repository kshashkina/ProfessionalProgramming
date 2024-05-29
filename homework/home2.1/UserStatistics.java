import java.io.*;
import java.util.HashMap;
import java.util.Map;

class UserStatistics {
    private Map<String, Integer> userStats;
    private final String fileName = "user_stats.txt";

    public UserStatistics() {
        userStats = new HashMap<>();
        loadFromFile();
    }

    public void close() {
        saveToFile();
    }

    public String greetUser(String name) {
        if (name.equals("bread")) {
            userStats.clear();
            saveToFile();
            return "All history has been exterminated.";
        }

        if (!userStats.containsKey(name)) {
            userStats.put(name, 1);
            return "Welcome, " + name + "!";
        } else {
            int count = userStats.get(name) + 1;
            userStats.put(name, count);
            return "Hello again(" + count + "), " + name + "!";
        }
    }

    public String resetUser(String name) {
        if (userStats.containsKey(name)) {
            userStats.remove(name);
            return "Statistics for " + name + " have been reset.";
        } else {
            return "No statistics to reset for " + name + ".";
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
