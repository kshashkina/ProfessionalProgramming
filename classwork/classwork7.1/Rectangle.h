#pragma once

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h);

    double getArea() const;

    bool canBePlacedInside(const Rectangle& other) const;

    double getBiggerSide() const;
};
