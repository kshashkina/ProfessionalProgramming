import java.io.IOException;
import java.util.*;
import java.util.concurrent.*;

public class FavoriteWords {
    public static void main(String[] args) {
        try {
            Config.getInstance().loadConfig("config.txt");
        } catch (IOException e) {
            System.err.println("Error loading configuration file: " + e.getMessage());
            return;
        }

        Scanner scanner = new Scanner(System.in);
        List<String> favoriteWords = new ArrayList<>();
        System.out.println("Enter your 5 favorite words:");
        for (int i = 0; i < 5; i++) {
            favoriteWords.add(scanner.nextLine());
        }
        scanner.close();

        ExecutorService executor = Executors.newFixedThreadPool(5);
        List<Future<?>> futures = new ArrayList<>();
        for (String word : favoriteWords) {
            futures.add(executor.submit(() -> processWord(word)));
        }

        for (Future<?> future : futures) {
            try {
                future.get();
            } catch (InterruptedException | ExecutionException e) {
                System.err.println("Error processing word: " + e.getMessage());
            }
        }
        executor.shutdown();
    }

    private static void processWord(String word) {
        try {
            Thread.sleep(1000);
            char firstLetter = Character.toLowerCase(word.charAt(0));
            String[] prePost = Config.getInstance().getPrePostWord(firstLetter);
            System.out.println(prePost[0] + " " + word + " " + prePost[1]);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}
