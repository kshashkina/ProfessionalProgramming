#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <print>
#include <format>

namespace {
    constexpr const char* DEFAULT_FILE_NAME = "user_stats.txt";
    constexpr const char* RESET_COMMAND = "bread";
    constexpr const char* DELETE_COMMAND = "delete";
}

class UserStatistics {
public:
    explicit UserStatistics(const std::string& statisticsFilePath = DEFAULT_FILE_NAME)
            : fileName(statisticsFilePath) {
        loadFromFile();
    }

    ~UserStatistics() {
        saveToFile();
    }

    int incrementCounterForUser(const std::string& name) {
        if (userStats.find(name) == userStats.end()) {
            userStats[name] = 1;
            return 1;
        } else {
            return ++userStats[name];
        }
    }

    bool resetUser(const std::string& name) {
        auto it = userStats.find(name);
        if (it != userStats.end()) {
            userStats.erase(it);
            return true;
        } else {
            return false;
        }
    }

    void resetAllUsers() {
        userStats.clear();
        saveToFile();
    }

private:
    std::unordered_map<std::string, int> userStats;
    std::string fileName;

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
            for (const auto& [name, count] : userStats) {
                std::println(file, "{} {}", name, count);
            }
            file.close();
        }
    }

};

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        return 1;
    }

    UserStatistics stats;

    std::string name = argv[1];
    bool isDeleteCmd = (argc == 3);
    std::string additionalCmd = isDeleteCmd ? argv[2] : "";

    if (isDeleteCmd && additionalCmd != DELETE_COMMAND) {
        std::cerr << "Error: Invalid command." << std::endl;
        return 1;
    }

    if (name == RESET_COMMAND) {
        stats.resetAllUsers();
        std::println("All history has been exterminated.");
    } else {
        if (!isDeleteCmd) {
            int count = stats.incrementCounterForUser(name);
            if (count == 1) {
                std::println("Welcome, {}!", name);
            } else {
                std::println("Hello again({}), {}!", count, name);
            }
        } else {
            if (stats.resetUser(name)) {
                std::println("Statistics for {} have been reset.", name);
            } else {
                std::println("No statistics to reset for {}.", name);
            }
        }
    }

    return 0;
}
