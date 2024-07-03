#include "Triangle.h"
#include <cmath>

double Triangle::area() const {
    if (a <= 0 || b <= 0 || c <= 0) {
        return -1; // Indicate invalid triangle
    }
    if (a + b <= c || a + c <= b || b + c <= a) {
        return -1; // Indicate invalid triangle
    }

    double s = (a + b + c) / 2.0;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}
