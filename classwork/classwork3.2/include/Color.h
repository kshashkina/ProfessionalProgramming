#pragma once

#include <tuple>

class Color {
public:
    Color(int r, int g, int b);

    std::tuple<int, int, int> getRGB() const;

    Color magicColor() const;

private:
    std::tuple<int, int, int> rgb;
};
