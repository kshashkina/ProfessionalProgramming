#include "UnitTests.h"
#include "PizzaDirector.cpp"
#include "CustomPizzaBuilder.cpp"

int main() {
    UnitTests testSuite;

    testSuite.addTest("TestCustomPizzaBuilder", []() {
        CustomPizzaBuilder builder;

        builder.addIngredient(Ingredient("Tomato", 1.5));
        builder.addIngredient(Ingredient("Cheese", 2.0));

        ASSERT_EQ(builder.getTotalCost(), 3.5);
    });

    testSuite.addTest("TestPizzaDirector", []() {
        auto builder = std::make_unique<CustomPizzaBuilder>();
        PizzaDirector director(std::move(builder));

        director.addIngredient(Ingredient("Tomato", 1.5));
        director.addIngredient(Ingredient("Cheese", 2.0));

        ASSERT_EQ(director.getPizzaCost(), 3.5);
    });

    testSuite.addTest("TestIngredientNotFound", []() {
        auto builder = std::make_unique<CustomPizzaBuilder>();
        PizzaDirector director(std::move(builder));

        director.addIngredient(Ingredient("NonExistentIngredient", 0.0));

        ASSERT_EQ(director.getPizzaCost(), 0.0);
    });

    testSuite.addTest("TestNoIngredientsAdded", []() {
        auto builder = std::make_unique<CustomPizzaBuilder>();
        PizzaDirector director(std::move(builder));

        ASSERT_EQ(director.getPizzaCost(), 0.0);
    });

    testSuite.addTest("TestSingleIngredient", []() {
        CustomPizzaBuilder builder;

        builder.addIngredient(Ingredient("Tomato", 1.5));

        ASSERT_EQ(builder.getTotalCost(), 1.5);
    });

    testSuite.addTest("TestDuplicateIngredients", []() {
        CustomPizzaBuilder builder;

        builder.addIngredient(Ingredient("Cheese", 2.0));
        builder.addIngredient(Ingredient("Cheese", 2.0));

        ASSERT_EQ(builder.getTotalCost(), 4.0);
    });

    testSuite.run();

    return 0;
}
