#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <tuple>
#include <cstdlib>

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

// Function to validate if an integer is in the range [0, 255]
bool isValidColorValue(int value) {
    return (value >= 0 && value <= 255);
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

// Function to process the image based on the favorite color
void processImage(const std::string &inputFileName, const std::tuple<int, int, int> &favoriteColor, const std::string &outputFileName) {
    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Failed to open input file");
    }

    std::vector<std::vector<std::tuple<int, int, int>>> image(16, std::vector<std::tuple<int, int, int>>(16));

    std::string line;
    int row = 0;
    while (std::getline(inputFile, line)) {
        if (row >= 16) {
            throw std::invalid_argument("Too many lines in input file");
        }
        image[row] = parseLine(line);
        if (image[row].size() != 16) {
            throw std::invalid_argument("Invalid number of pixels in a line");
        }
        ++row;
    }
    inputFile.close();

    if (row != 16) {
        throw std::invalid_argument("Not enough lines in input file");
    }

    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            if (image[i][j] == favoriteColor) {
                if (i > 0 && j > 0) {
                    image[i-1][j-1] = favoriteColor;
                }
            }
        }
    }

    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        throw std::runtime_error("Failed to open output file");
    }

    for (const auto &row : image) {
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

int main(int argc, char *argv[]) {
    if (argc != 6) {
        std::cerr << "Usage: " << argv[0] << " <input file> <R> <G> <B> <output file>\n";
        return 1;
    }

    std::string inputFileName = argv[1];
    int r = std::atoi(argv[2]);
    int g = std::atoi(argv[3]);
    int b = std::atoi(argv[4]);
    std::string outputFileName = argv[5];

    if (!isValidColorValue(r) || !isValidColorValue(g) || !isValidColorValue(b)) {
        std::cerr << "Error: Invalid favorite color value. Each component must be in the range [0, 255].\n";
        return 1;
    }

    try {
        processImage(inputFileName, std::make_tuple(r, g, b), outputFileName);
        std::cout << "Image processing complete.\n";
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
