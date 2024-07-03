#include "Color.h"
#include <algorithm>

Color::Color(int r, int g, int b) : rgb(std::make_tuple(r, g, b)) {}

std::tuple<int, int, int> Color::getRGB() const {
    return rgb;
}

Color Color::magicColor() const {
    int r = std::get<0>(rgb);
    int g = std::get<1>(rgb);
    int b = std::get<2>(rgb);

    int newR = (r / 2) - 1;
    int newG = (g * 2) - 2;
    int newB = b; // Unchanged

    // Ensure the values stay within the range 0-255
    newR = std::max(0, std::min(255, newR));
    newG = std::max(0, std::min(255, newG));

    return Color(newR, newG, newB);
}
