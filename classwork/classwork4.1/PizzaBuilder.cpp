#pragma once

#include <vector>
#include <memory>
#include "Ingredient.cpp"
#include "Pizza.cpp"

// Abstract PizzaBuilder class to construct pizzas
class PizzaBuilder {
protected:
    std::vector<Ingredient> selectedIngredients;

public:
    virtual ~PizzaBuilder() = default;

    virtual void addIngredient(const Ingredient& ingredient) {
        selectedIngredients.push_back(ingredient);
    }

    virtual std::unique_ptr<Pizza> buildPizza() = 0;
};