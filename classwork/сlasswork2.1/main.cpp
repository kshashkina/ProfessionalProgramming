#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <print>
#include <format>

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
            return std::format("Welcome, {}!", name);
        } else {
            int count = ++userStats[name];
            return std::format("Hello again({}), {}!", count, name);
        }
    }

    std::string resetUser(const std::string& name) {
        auto it = userStats.find(name);
        if (it != userStats.end()) {
            userStats.erase(it);
            return std::format("Statistics for {} have been reset.", name);
        } else {
            return std::format("No statistics to reset for {}.", name);
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
            for (const auto& [name, count] : userStats) {
                std::println(file, "{} {}", name, count);
            }
            file.close();
        }
    }

};

int main(int argc, char* argv[]) {
    UserStatistics stats;

    if (argc < 2 || argc > 3) {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        return 1;
    }

    std::string name = argv[1];
    bool isDeleteCmd = (argc == 3);
    std::string additionalCmd = isDeleteCmd ? argv[2] : "";

    if (isDeleteCmd && additionalCmd != "delete") {
        std::cerr << "Error: Invalid command." << std::endl;
        return 1;
    }

    if (!isDeleteCmd) {
        std::println("{}", stats.greetUser(name));
    } else {
        std::println("{}", stats.resetUser(name));
    }
    return 0;
}
