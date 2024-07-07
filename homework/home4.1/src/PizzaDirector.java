// Director class to construct pizzas using a builder
public class PizzaDirector {
    private PizzaBuilder builder;

    public PizzaDirector(PizzaBuilder _builder) {
        builder = _builder;
    }

    public void addIngredient(Ingredient ingredient) {
        builder.addIngredient(ingredient);
    }

    public double getPizzaCost() {
        return builder.getTotalCost();
    }

    public void displayPizza() {
        builder.displayPizza();
    }
}
