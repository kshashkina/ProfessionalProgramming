// PizzaBuilder interface to construct pizzas
public interface PizzaBuilder {
    void addIngredient(Ingredient ingredient);
    double getTotalCost();
    void displayPizza();
}
