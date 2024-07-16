import java.util.Objects;

// Ingredient class to represent each ingredient
public class Ingredient {
    private final String name;
    private final double cost;

    public Ingredient(String _name, double _cost) {
        name = _name;
        cost = _cost;
    }

    public String getName() {
        return name;
    }

    public double getCost() {
        return cost;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Ingredient that = (Ingredient) o;
        return Double.compare(that.cost, cost) == 0 &&
                Objects.equals(name, that.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, cost);
    }
}
