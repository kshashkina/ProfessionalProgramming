#pragma once

#include <memory>
#include "PizzaBuilder.cpp"

class PizzaDirector {
private:
    std::unique_ptr<PizzaBuilder> builder;

public:
    PizzaDirector(std::unique_ptr<PizzaBuilder> _builder) : builder(std::move(_builder)) {}

    void addIngredient(const Ingredient& ingredient) {
        builder->addIngredient(ingredient);
    }

    std::unique_ptr<Pizza> constructPizza() {
        return builder->buildPizza();
    }
};
