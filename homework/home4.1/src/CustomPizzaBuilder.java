import java.util.HashMap;
import java.util.Map;

// Concrete implementation of PizzaBuilder for creating custom pizzas
public class CustomPizzaBuilder implements PizzaBuilder {
    private Map<Ingredient, Integer> selectedIngredients = new HashMap<>();

    @Override
    public void addIngredient(Ingredient ingredient) {
        selectedIngredients.put(ingredient, selectedIngredients.getOrDefault(ingredient, 0) + 1);
    }

    @Override
    public double getTotalCost() {
        double totalCost = 0.0;
        for (Map.Entry<Ingredient, Integer> entry : selectedIngredients.entrySet()) {
            totalCost += entry.getKey().getCost() * entry.getValue();
        }
        return totalCost;
    }

    @Override
    public void displayPizza() {
        System.out.println("Your pizza ingredients:");
        for (Map.Entry<Ingredient, Integer> entry : selectedIngredients.entrySet()) {
            System.out.printf("- %s ($%.2f) x %d%n", entry.getKey().getName(), entry.getKey().getCost(), entry.getValue());
        }
        System.out.printf("Total cost: $%.2f%n", getTotalCost());
    }
}
