import java.util.List;

public interface PizzaBuilder {
    void addIngredient(Ingredient ingredient);
    Pizza buildPizza();
}
