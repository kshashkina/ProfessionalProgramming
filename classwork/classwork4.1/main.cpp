#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <memory>
#include <print>

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
