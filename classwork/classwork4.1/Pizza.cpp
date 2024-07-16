#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <numeric>
#include "Ingredient.cpp"

class Pizza {
private:
    std::vector<Ingredient> ingredients;

public:
    Pizza(const std::vector<Ingredient>& _ingredients) : ingredients(_ingredients) {}

    double getTotalCost() const {
        return std::accumulate(ingredients.begin(), ingredients.end(), 0.0,
                               [](double sum, const Ingredient& ingredient) {
                                   return sum + ingredient.getCost();
                               });
    }

    void displayPizza() const {
        std::println("Your pizza ingredients:");
        for (const auto& ingredient : selectedIngredients) {
            std::println("- {} (${})", ingredient.getName(), ingredient.getCost());
        }
        std::println("Total cost: ${}", getTotalCost());
    }
};
