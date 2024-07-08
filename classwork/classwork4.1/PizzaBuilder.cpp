#pragma once


#include "Ingredient.cpp"

// Abstract PizzaBuilder class to construct pizzas
class PizzaBuilder {
protected:
    std::vector<Ingredient> selectedIngredients;

public:
    virtual ~PizzaBuilder() = default;

    virtual void addIngredient(const Ingredient& ingredient) {
        selectedIngredients.push_back(ingredient);
    }

    virtual double getTotalCost() const = 0;
    virtual void displayPizza() const = 0;
};