#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <tuple>
#include <stdexcept>
#include <print>
#include <optional>

// Class to represent RGB color
class Color {
private:
    int r;
    int g;
    int b;

public:
    Color(int red, int green, int blue) : r(red), g(green), b(blue) {}

    bool isValid() const {
        return (isValidColorValue(r) && isValidColorValue(g) && isValidColorValue(b));
    }

    int getRed() const { return r; }
    int getGreen() const { return g; }
    int getBlue() const { return b; }

    // Static method to create a Color object from command-line arguments
    static std::optional<Color> fromArgs(const char *argv[]) {
        int r = std::atoi(argv[0]);
        int g = std::atoi(argv[1]);
        int b = std::atoi(argv[2]);

        if (!isValidColorValue(r) || !isValidColorValue(g) || !isValidColorValue(b)) {
            std::cerr << "Error: Invalid color value. Each component must be in the range [0, 255].\n";
            return std::nullopt;
        }

        return Color(r, g, b);
    }

private:
    static bool isValidColorValue(int value) {
        return (value >= 0 && value <= 255);
    }
};


// Class to represent an image
class Image {
private:
    static constexpr int WIDTH = 16;
    static constexpr int HEIGHT = 16;
    std::vector<std::vector<std::tuple<int, int, int>>> pixels;

public:
    Image() : pixels(HEIGHT, std::vector<std::tuple<int, int, int>>(WIDTH)) {}

    void read(const std::string &inputFileName) {
        std::ifstream inputFile(inputFileName);
        if (!inputFile.is_open()) {
            throw std::runtime_error("Failed to open input file");
        }

        std::string line;
        int row = 0;
        while (std::getline(inputFile, line)) {
            if (row >= HEIGHT) {
                throw std::invalid_argument("Too many lines in input file");
            }
            pixels[row] = parseLine(line);
            if (pixels[row].size() != WIDTH) {
                throw std::invalid_argument("Invalid number of pixels in a line");
            }
            ++row;
        }
        inputFile.close();

        if (row != HEIGHT) {
            throw std::invalid_argument("Not enough lines in input file");
        }
    }

    void write(const std::string &outputFileName) {
        std::ofstream outputFile(outputFileName);
        if (!outputFile.is_open()) {
            throw std::runtime_error("Failed to open output file");
        }

        for (const auto &row : pixels) {
            for (size_t j = 0; j < row.size(); ++j) {
                outputFile << std::get<0>(row[j]) << "," << std::get<1>(row[j]) << "," << std::get<2>(row[j]);
                if (j < row.size() - 1) {
                    outputFile << " ";
                }
            }
            outputFile << "\n";
        }
        outputFile.close();
    }

    // Process image based on favorite and unfavorite colors
    void process(const Color &favoriteColor, const Color &unfavoriteColor = Color(-1, -1, -1)) {
        for (int i = 0; i < HEIGHT; ++i) {
            for (int j = 0; j < WIDTH; ++j) {
                if (pixels[i][j] == std::make_tuple(favoriteColor.getRed(), favoriteColor.getGreen(), favoriteColor.getBlue())) {
                    if (i > 0 && j > 0) {
                        pixels[i - 1][j - 1] = std::make_tuple(favoriteColor.getRed(), favoriteColor.getGreen(), favoriteColor.getBlue());
                    }
                }
                if (pixels[i][j] == std::make_tuple(unfavoriteColor.getRed(), unfavoriteColor.getGreen(), unfavoriteColor.getBlue())) {
                    pixels[i][j] = std::make_tuple(favoriteColor.getRed(), favoriteColor.getGreen(), favoriteColor.getBlue());
                }
            }
        }
    }

private:
    // Function to split string by a delimiter
    std::vector<std::string> split(const std::string &str, char delimiter) {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(str);
        while (std::getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    // Function to validate if a string represents a valid integer in the range [0, 255]
    bool isValidColorValue(const std::string &str) {
        try {
            int value = std::stoi(str);
            return (value >= 0 && value <= 255);
        } catch (...) {
            return false;
        }
    }

    // Function to parse a line into a vector of pixels
    std::vector<std::tuple<int, int, int>> parseLine(const std::string &line) {
        std::vector<std::tuple<int, int, int>> pixels;
        std::vector<std::string> parts = split(line, ' ');
        for (const std::string &part : parts) {
            std::vector<std::string> colorValues = split(part, ',');
            if (colorValues.size() != 3 ||
                !isValidColorValue(colorValues[0]) ||
                !isValidColorValue(colorValues[1]) ||
                !isValidColorValue(colorValues[2])) {
                throw std::invalid_argument("Invalid pixel format");
            }
            pixels.emplace_back(std::stoi(colorValues[0]), std::stoi(colorValues[1]), std::stoi(colorValues[2]));
        }
        return pixels;
    }
};

int main(int argc, char *argv[]) {
    if (argc != 6 && argc != 9) {
        std::cerr << "Usage: " << argv[0] << " <input file> <R> <G> <B> <output file> [unfavorite R] [unfavorite G] [unfavorite B]\n";
        return 1;
    }

    std::string inputFileName = argv[1];

    // Create favorite color from arguments
    auto favoriteColor = Color::fromArgs(const_cast<const char **>(argv + 2));
    if (!favoriteColor.has_value()) {
        std::cerr << "Error: Invalid favorite color.\n";
        return 1;
    }

    std::string outputFileName = argv[5];

    // Create unfavorite color if specified
    std::optional<Color> unfavoriteColor;
    if (argc == 9) {
        unfavoriteColor = Color::fromArgs(const_cast<const char **>(argv + 6));
        if (!unfavoriteColor.has_value()) {
            std::cerr << "Error: Invalid unfavorite color.\n";
            return 1;
        }
    }

    try {
        Image image;
        image.read(inputFileName);
        image.process(*favoriteColor, unfavoriteColor.value_or(Color(-1, -1, -1)));
        image.write(outputFileName);
        std::cout << "Image processing complete.\n";
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}

