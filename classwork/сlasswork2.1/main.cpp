#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <print>

class UserStatistics {
public:
    UserStatistics() {
        loadFromFile();
    }

    ~UserStatistics() {
        saveToFile();
    }

    std::string greetUser(const std::string& name) {
        if (name == "bread") {
            userStats.clear();
            saveToFile();
            return "All history has been exterminated.";
        }

        if (userStats.find(name) == userStats.end()) {
            userStats[name] = 1;
            return "Welcome, " + name + "!";
        } else {
            int count = ++userStats[name];
            return "Hello again(" + std::to_string(count) + "), " + name + "!";
        }
    }

    std::string resetUser(const std::string& name) {
        auto it = userStats.find(name);
        if (it != userStats.end()) {
            userStats.erase(it);
            return "Statistics for " + name + " have been reset.";
        } else {
            return "No statistics to reset for " + name + ".";
        }
    }
private:
    std::unordered_map<std::string, int> userStats;
    const std::string fileName = "user_stats.txt";

    void loadFromFile() {
        std::ifstream file(fileName);
        if (file.is_open()) {
            std::string name;
            int count;
            while (file >> name >> count) {
                userStats[name] = count;
            }
            file.close();
        }
    }

    void saveToFile() {
        std::ofstream file(fileName);
        if (file.is_open()) {
            for (const auto& entry : userStats) {
                file << entry.first << " " << entry.second << "\n";
            }
            file.close();
        }
    }

};

int main(int argc, char* argv[]) {
    UserStatistics stats;

    if (argc < 2) {
        std::println("Error: Please provide a name as an argument.");
        return 1;
    }

    std::string name = argv[1];

    if (argc == 2) {
        std::println("{}", stats.greetUser(name));
    } else if (argc == 3 && std::string(argv[2]) == "delete") {
        std::println("{}", stats.resetUser(name));
    } else {
        std::println("Error: Invalid arguments.");
        return 1;
    }
    return 0;
}
