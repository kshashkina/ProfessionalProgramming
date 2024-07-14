import java.util.*;
import java.util.concurrent.ConcurrentHashMap;
import java.util.function.Consumer;

public class MessageDispatcher {
    private final Map<Class<?>, Map<UUID, Consumer<?>>> subscribersMap = new ConcurrentHashMap<>();

    public <MessageType> UUID subscribe(Class<MessageType> messageType, Consumer<MessageType> callback) {
        UUID id = UUID.randomUUID();
        subscribersMap.computeIfAbsent(messageType, k -> new ConcurrentHashMap<>()).put(id, callback);
        return id;
    }

    public <MessageType> void publish(MessageType message) {
        Class<?> messageType = message.getClass();
        Map<UUID, Consumer<?>> subscribers = subscribersMap.get(messageType);
        if (subscribers != null) {
            for (Consumer<?> subscriber : subscribers.values()) {
                ((Consumer<MessageType>) subscriber).accept(message);
            }
        }
    }

    public void unsubscribe(UUID id) {
        for (Map<UUID, Consumer<?>> subscribers : subscribersMap.values()) {
            subscribers.remove(id);
        }
    }
}
