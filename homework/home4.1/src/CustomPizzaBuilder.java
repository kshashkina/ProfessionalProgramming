import java.util.ArrayList;
import java.util.List;

public class CustomPizzaBuilder implements PizzaBuilder {
    private List<Ingredient> selectedIngredients = new ArrayList<>();

    @Override
    public void addIngredient(Ingredient ingredient) {
        selectedIngredients.add(ingredient);
    }

    @Override
    public Pizza buildPizza() {
        return new Pizza(new ArrayList<>(selectedIngredients));
    }
}
