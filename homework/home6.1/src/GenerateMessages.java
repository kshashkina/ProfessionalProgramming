import java.util.*;
import java.util.concurrent.atomic.AtomicBoolean;

public class GenerateMessages implements Runnable {
    private final MessageDispatcher dispatcher;
    private final AtomicBoolean running;

    public GenerateMessages(MessageDispatcher dispatcher, AtomicBoolean running) {
        this.dispatcher = dispatcher;
        this.running = running;
    }

    @Override
    public void run() {
        Random random = new Random();
        String[] words = {"Hello", "World", "Test", "Message"};

        while (running.get()) {
            int msgType = random.nextInt(3);
            switch (msgType) {
                case 0 -> {
                    GreenMessage msg = new GreenMessage(words[random.nextInt(words.length)], random.nextInt(100));
                    dispatcher.publish(msg);
                }
                case 1 -> {
                    BlueMessage msg = new BlueMessage(random.nextDouble() * 100, random.nextDouble() * 100);
                    dispatcher.publish(msg);
                }
                case 2 -> {
                    OrangeMessage msg = new OrangeMessage(
                            words[random.nextInt(words.length)],
                            words[random.nextInt(words.length)],
                            random.nextInt(100),
                            random.nextDouble() * 100);
                    dispatcher.publish(msg);
                }
            }
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}
