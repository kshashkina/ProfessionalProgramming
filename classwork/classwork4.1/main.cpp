#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <memory>
#include <print>
#include "PizzaDirector.cpp"
#include "CustomPizzaBuilder.cpp"

// Function to read ingredients and their costs from a file
std::map<std::string, double> readIngredients(const std::string& filename) {
    std::ifstream file(filename);
    std::map<std::string, double> ingredients;
    std::string name;
    double cost;

    while (file >> name >> cost) {
        ingredients[name] = cost;
    }

    return ingredients;
}

int main() {
    const std::string filename = "ingredients.txt";
    std::map<std::string, double> ingredientCosts = readIngredients(filename);

    std::println("Welcome to the Pizza Composer!\nAvailable ingredients and costs:");

    // Print available ingredients
    for (const auto& pair : ingredientCosts) {
        std::println("- {} (${})", pair.first, pair.second);
    }

    std::println("Start composing your pizza! Enter ingredients one by one.\nEnter 'done' when finished.");

    auto customPizzaBuilder = std::make_unique<CustomPizzaBuilder>(); // Create a CustomPizzaBuilder object
    PizzaDirector director(std::move(customPizzaBuilder)); // Create a PizzaDirector with the builder

    std::string input;
    while (true) {
        std::getline(std::cin, input);

        if (input == "done") {
            break;
        }

        // Check if the ingredient exists in the map
        auto it = ingredientCosts.find(input);
        if (it != ingredientCosts.end()) {
            Ingredient newIngredient(it->first, it->second);
            director.addIngredient(newIngredient);
        } else {
            std::println("Ingredient not found. Please enter a valid ingredient.");
        }
    }

    // Display the pizza ingredients and total cost using the director
    std::println("");
    director.displayPizza();

    return 0;
}
