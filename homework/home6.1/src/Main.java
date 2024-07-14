import java.util.UUID;
import java.util.concurrent.atomic.AtomicBoolean;

public class Main {
    public static void main(String[] args) {
        MessageDispatcher dispatcher = new MessageDispatcher();
        AtomicBoolean running = new AtomicBoolean(true);

        UUID greenSubscriptionId = dispatcher.subscribe(GreenMessage.class, msg -> {
            System.out.println("Received GreenMessage: " + msg.text + ", " + msg.counter);
        });

        UUID blueSubscriptionId = dispatcher.subscribe(BlueMessage.class, msg -> {
            System.out.println("Received BlueMessage: " + msg.value1 + ", " + msg.value2);
        });

        UUID orangeSubscriptionId = dispatcher.subscribe(OrangeMessage.class, msg -> {
            System.out.println("Received OrangeMessage: " + msg.text1 + ", " + msg.text2 + ", " + msg.counter + ", " + msg.value);
        });

        Thread t1 = new Thread(new GenerateMessages(dispatcher, running));
        Thread t2 = new Thread(new GenerateMessages(dispatcher, running));

        t1.start();
        t2.start();

        try {
            Thread.sleep(10000);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
        running.set(false);

        dispatcher.unsubscribe(greenSubscriptionId);
        dispatcher.unsubscribe(blueSubscriptionId);
        dispatcher.unsubscribe(orangeSubscriptionId);

        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}
