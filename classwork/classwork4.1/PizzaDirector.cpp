#pragma once


#include "CustomPizzaBuilder.cpp"

// Director class to construct pizzas using a builder
class PizzaDirector {
private:
    std::unique_ptr<PizzaBuilder> builder;

public:
    PizzaDirector(std::unique_ptr<PizzaBuilder> _builder) : builder(std::move(_builder)) {}

    void addIngredient(const Ingredient& ingredient) {
        builder->addIngredient(ingredient);
    }

    double getPizzaCost() const {
        return builder->getTotalCost();
    }

    void displayPizza() const {
        builder->displayPizza();
    }
};