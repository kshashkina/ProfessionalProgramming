#include "Rectangle.h"
#include <algorithm>

Rectangle::Rectangle(double w, double h) : width(w), height(h) {}

double Rectangle::getArea() const {
    return width * height;
}

bool Rectangle::canBePlacedInside(const Rectangle& other) const {
    return (width <= other.width && height <= other.height);
}

double Rectangle::getBiggerSide() const {
    return std::max(width, height);
}
