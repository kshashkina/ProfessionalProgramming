import java.io.*;
import java.util.*;
import java.util.concurrent.locks.*;

class Config {
    private static Config instance;
    private static final Lock lock = new ReentrantLock();
    private Map<Character, String[]> configMap = new HashMap<>();

    private Config() {
    }

    public static Config getInstance() {
        if (instance == null) {
            lock.lock();
            try {
                if (instance == null) {
                    instance = new Config();
                }
            } finally {
                lock.unlock();
            }
        }
        return instance;
    }

    public void loadConfig(String filename) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(filename));
        String line;
        while ((line = reader.readLine()) != null) {
            String[] parts = line.split(" ");
            if (parts.length != 4) {
                System.err.println("Invalid configuration line: " + line);
                continue;
            }
            char start = parts[0].charAt(0);
            char end = parts[1].charAt(0);
            String pre = parts[2];
            String post = parts[3];
            for (char c = start; c <= end; c++) {
                configMap.put(c, new String[]{pre, post});
            }
        }
        reader.close();
    }

    public String[] getPrePostWord(char firstLetter) {
        return configMap.getOrDefault(firstLetter, new String[]{"", ""});
    }
}
