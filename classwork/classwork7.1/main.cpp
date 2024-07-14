#include <iostream>
#include <vector>
#include <algorithm>
#include <print>

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const {
        return width * height;
    }

    bool canBePlacedInside(const Rectangle& other) const {
        return (width <= other.width && height <= other.height);
    }

    double getBiggerSide() const {
        return std::max(width, height);
    }
};

int main() {
    std::vector<Rectangle> rectangles;

    for (int i = 0; i < 5; ++i) {
        double width, height;
        std::println("Enter rectangle {} (width height):", (i + 1));
        if (std::cin >> width >> height) {
            rectangles.emplace_back(width, height);
        }
    }

    // Finding the rectangle with the biggest area
    auto maxAreaRect = std::max_element(rectangles.begin(), rectangles.end(),
                                        [](const Rectangle& r1, const Rectangle& r2) {
                                            return r1.getArea() < r2.getArea();
                                        });

    std::println("The biggest area: {}", maxAreaRect->getArea());
    std::println("Number of rectangles: {}", rectangles.size());

    // Finding the rectangle with the smallest area
    auto minAreaRect = std::min_element(rectangles.begin(), rectangles.end(),
                                        [](const Rectangle& r1, const Rectangle& r2) {
                                            return r1.getArea() < r2.getArea();
                                        });

    std::println("The smallest area: {}", minAreaRect->getArea());

    // Checking which rectangles can be placed inside others
    for (const auto& r1 : rectangles) {
        for (const auto& r2 : rectangles) {
            if (&r1 != &r2 && r1.canBePlacedInside(r2)) {
                std::println("Rectangle {}  can be placed inside Rectangle {}", (&r1 - &rectangles[0] + 1), (&r2 - &rectangles[0] + 1));
            }
        }
    }

    // Printing the biggest side of each rectangle
    for (const auto& rect : rectangles) {
        std::println("The biggest side of rectangle {}: {}",(&rect - &rectangles[0] + 1), rect.getBiggerSide());
    }

    // Total area of all rectangles
    double totalArea = 0;
    for (const auto& rect : rectangles) {
        totalArea += rect.getArea();
    }
    std::println("Total area of rectangles: {}", totalArea);

    return 0;
}
