#pragma once

class Triangle {
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}
    double area() const;
private:
    double a, b, c;
};
