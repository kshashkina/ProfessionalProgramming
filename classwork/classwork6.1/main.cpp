#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <random>
#include <typeindex>
#include <atomic>

struct GreenMessage {
    std::string text;
    int counter;
};

struct BlueMessage {
    double value1;
    double value2;
};

struct OrangeMessage {
    std::string text1;
    std::string text2;
    int counter;
    double value;
};

class MessageDispatcher {
public:
    template<typename MessageType>
    void subscribe(std::function<void(const MessageType&)> callback) {
        std::lock_guard<std::mutex> lock(mtx);
        auto& subscribers = getSubscribers<MessageType>();
        subscribers.push_back([callback](const auto& msg) {
            callback(static_cast<const MessageType&>(msg));
        });
    }

    template<typename MessageType>
    void publish(const MessageType& message) {
        std::lock_guard<std::mutex> lock(mtx);
        auto& subscribers = getSubscribers<MessageType>();
        for (auto& subscriber : subscribers) {
            subscriber(message);
        }
    }

private:
    std::mutex mtx;
    std::unordered_map<std::type_index, std::vector<std::function<void(const void*)>>> subscribersMap;

    template<typename MessageType>
    std::vector<std::function<void(const MessageType&)>>& getSubscribers() {
        auto typeIndex = std::type_index(typeid(MessageType));
        if (subscribersMap.find(typeIndex) == subscribersMap.end()) {
            subscribersMap[typeIndex] = std::vector<std::function<void(const void*)>>();
        }
        return *reinterpret_cast<std::vector<std::function<void(const MessageType&)>>*>(&subscribersMap[typeIndex]);
    }
};

// Function to generate random messages
void generateMessages(MessageDispatcher& dispatcher, std::atomic<bool>& running) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 2);
    std::uniform_int_distribution<> intDist(1, 100);
    std::uniform_real_distribution<> doubleDist(1.0, 100.0);
    std::vector<std::string> words = {"Hello", "World", "Test", "Message"};

    while (running) {
        int msgType = dist(gen);
        switch (msgType) {
            case 0: {
                GreenMessage msg { words[intDist(gen) % words.size()], intDist(gen) };
                dispatcher.publish(msg);
                break;
            }
            case 1: {
                BlueMessage msg { doubleDist(gen), doubleDist(gen) };
                dispatcher.publish(msg);
                break;
            }
            case 2: {
                OrangeMessage msg { words[intDist(gen) % words.size()], words[intDist(gen) % words.size()], intDist(gen), doubleDist(gen) };
                dispatcher.publish(msg);
                break;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main() {
    MessageDispatcher dispatcher;
    std::atomic<bool> running(true);

    dispatcher.subscribe<GreenMessage>([](const GreenMessage& msg) {
        std::println("Received GreenMessage: {}, {}", msg.text, msg.counter);
    });

    dispatcher.subscribe<BlueMessage>([](const BlueMessage& msg) {
        std::println("Received BlueMessage: {}, {}", msg.value1, msg.value2);
    });

    dispatcher.subscribe<OrangeMessage>([](const OrangeMessage& msg) {
        std::println("Received OrangeMessage: {}, {}, {}, {}", msg.text1, msg.text2, msg.counter, msg.value);
    });

    std::thread t1(generateMessages, std::ref(dispatcher), std::ref(running));
    std::thread t2(generateMessages, std::ref(dispatcher), std::ref(running));

    std::this_thread::sleep_for(std::chrono::seconds(10));
    running = false;

    t1.join();
    t2.join();

    return 0;
}
