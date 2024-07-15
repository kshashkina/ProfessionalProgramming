#pragma once

#include <string>

// Ingredient class to represent each ingredient
class Ingredient {
private:
    std::string name;
    double cost;

public:
    Ingredient(const std::string& _name, double _cost) : name(_name), cost(_cost) {}
    std::string getName() const { return name; }
    double getCost() const { return cost; }
};