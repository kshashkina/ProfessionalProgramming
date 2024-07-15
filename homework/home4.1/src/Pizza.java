import java.util.List;

public class Pizza {
    private final List<Ingredient> ingredients;

    public Pizza(List<Ingredient> ingredients) {
        this.ingredients = ingredients;
    }

    public double getTotalCost() {
        return ingredients.stream().mapToDouble(Ingredient::getCost).sum();
    }

    public void displayPizza() {
        System.out.println("Your pizza ingredients:");
        ingredients.forEach(ingredient ->
                System.out.printf("- %s ($%.2f)%n", ingredient.getName(), ingredient.getCost()));
        System.out.printf("Total cost: $%.2f%n", getTotalCost());
    }
}
