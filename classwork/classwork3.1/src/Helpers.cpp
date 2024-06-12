#include "Helpers.hpp"

std::string repeatString(const std::vector<int>& vec, const std::string& str) {
    if (vec.empty()) {
        return "";
    }
    int maxVal = *std::max_element(vec.begin(), vec.end());
    std::string result;
    for (int i = 0; i < maxVal; ++i) {
        result += str;
    }
    return result;
}
