public class PizzaDirector {
    private final PizzaBuilder builder;

    public PizzaDirector(PizzaBuilder builder) {
        this.builder = builder;
    }

    public void addIngredient(Ingredient ingredient) {
        builder.addIngredient(ingredient);
    }

    public Pizza constructPizza() {
        return builder.buildPizza();
    }
}
