#pragma once


#include "PizzaBuilder.cpp"

// Concrete implementation of PizzaBuilder for creating custom pizzas
class CustomPizzaBuilder : public PizzaBuilder {
public:
    double getTotalCost() const override {
        double totalCost = 0.0;
        for (const auto& ingredient : selectedIngredients) {
            totalCost += ingredient.getCost();
        }
        return totalCost;
    }

    void displayPizza() const override {
        std::println("Your pizza ingredients:");
        for (const auto& ingredient : selectedIngredients) {
            std::println("- {} (${})", ingredient.getName(), ingredient.getCost());
        }
        std::println("Total cost: ${}", getTotalCost());
    }
};