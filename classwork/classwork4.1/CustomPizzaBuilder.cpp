#pragma once


#include "PizzaBuilder.cpp"

// Concrete implementation of PizzaBuilder for creating custom pizzas
class CustomPizzaBuilder : public PizzaBuilder {
public:
    std::unique_ptr<Pizza> buildPizza() override {
        return std::make_unique<Pizza>(selectedIngredients);
    }
};
