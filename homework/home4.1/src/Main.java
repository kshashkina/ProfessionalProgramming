import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    private static final String DONE_COMMAND = "done";

    // Read ingredients from file
    private static Map<String, Double> readIngredients(String filename) throws FileNotFoundException {
        Map<String, Double> ingredients = new HashMap<>();
        try (Scanner scanner = new Scanner(new File(filename))) {
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine().trim();
                String[] parts = line.split(" ");
                if (parts.length < 2) {
                    System.err.println("Invalid input format for ingredient: " + line);
                    continue;
                }

                String name = parts[0];
                double cost = Double.parseDouble(parts[1]);

                ingredients.put(name, cost);
            }
        } catch (FileNotFoundException e) {
            System.err.println("File not found: " + filename);
            throw e;
        } catch (NumberFormatException e) {
            System.err.println("Invalid cost format for ingredient: " + e.getMessage());
        }

        return ingredients;
    }

    // Read default pizzas from file
    private static Map<String, Map<String, Double>> readPizzas(String filename) throws FileNotFoundException {
        Map<String, Map<String, Double>> pizzas = new HashMap<>();
        try (Scanner scanner = new Scanner(new File(filename))) {
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] parts = line.split(" ");
                String pizzaName = parts[0];
                Map<String, Double> pizzaIngredients = new HashMap<>();
                for (int i = 1; i < parts.length; i += 2) {
                    String ingredientName = parts[i];
                    double ingredientCost = Double.parseDouble(parts[i + 1]);
                    pizzaIngredients.put(ingredientName, ingredientCost);
                }
                pizzas.put(pizzaName, pizzaIngredients);
            }
        } catch (FileNotFoundException e) {
            System.err.println("File not found: " + filename);
            throw e;
        } catch (NumberFormatException | NoSuchElementException e) {
            System.err.println("Invalid format in file: " + filename);
        }
        return pizzas;
    }

    public static void main(String[] args) {
        final String ingredientsFile = "ingredients.txt";
        final String pizzasFile = "pizzas.txt";

        Map<String, Double> ingredientCosts;
        Map<String, Map<String, Double>> defaultPizzas;

        try {
            ingredientCosts = readIngredients(ingredientsFile);
            defaultPizzas = readPizzas(pizzasFile);
        } catch (FileNotFoundException e) {
            System.err.println("Error reading files: " + e.getMessage());
            return;
        }

        System.out.println("Welcome to the Pizza Composer!");
        System.out.println("Do you want to compose a custom pizza? (yes/no)");

        Scanner scanner = new Scanner(System.in);
        String choice = scanner.nextLine().trim().toLowerCase();

        if ("yes".equals(choice)) {
            composeCustomPizza(scanner, ingredientCosts);
        } else if ("no".equals(choice)) {
            chooseDefaultPizza(scanner, defaultPizzas, ingredientCosts);
        } else {
            System.out.println("Invalid choice. Please enter 'yes' or 'no'.");
        }

        scanner.close();
    }

    // Compose a custom pizza by adding ingredients based on user input
    private static void composeCustomPizza(Scanner scanner, Map<String, Double> ingredientCosts) {
        CustomPizzaBuilder customPizzaBuilder = new CustomPizzaBuilder();
        PizzaDirector director = new PizzaDirector(customPizzaBuilder);

        System.out.println("Available ingredients and costs:");
        ingredientCosts.forEach((name, cost) -> System.out.printf("- %s ($%.2f)%n", name, cost));

        System.out.println("Start composing your pizza! Enter ingredients one by one.");
        System.out.println("Enter '" + DONE_COMMAND + "' when finished.");

        while (true) {
            String input = scanner.nextLine().trim();

            if (DONE_COMMAND.equalsIgnoreCase(input)) {
                break;
            }

            if (ingredientCosts.containsKey(input)) {
                Ingredient newIngredient = new Ingredient(input, ingredientCosts.get(input));
                director.addIngredient(newIngredient);
            } else {
                System.out.println("Ingredient not found. Please enter a valid ingredient.");
            }
        }

        Pizza pizza = director.constructPizza();
        pizza.displayPizza();
    }

    // Choose a default pizza option from the list
    private static void chooseDefaultPizza(Scanner scanner, Map<String, Map<String, Double>> defaultPizzas, Map<String, Double> ingredientCosts) {
        System.out.println("Please choose from the following classical options:");

        int index = 1;
        for (String pizzaName : defaultPizzas.keySet()) {
            double pizzaCost = calculatePizzaCost(defaultPizzas.get(pizzaName));
            System.out.printf("%d. %s ($%.2f)%n", index++, pizzaName, pizzaCost);
        }

        System.out.println("Enter the number of your choice:");

        try {
            int option = Integer.parseInt(scanner.nextLine().trim());
            if (option >= 1 && option <= defaultPizzas.size()) {
                String pizzaName = (String) defaultPizzas.keySet().toArray()[option - 1];
                Map<String, Double> pizzaIngredients = defaultPizzas.get(pizzaName);
                buildDefaultPizza(pizzaName, pizzaIngredients, ingredientCosts);
            } else {
                System.out.println("Invalid option selected.");
            }
        } catch (NumberFormatException e) {
            System.out.println("Invalid input. Please enter a number.");
        }
    }

    // Calculate the total cost of a pizza based on its ingredients
    private static double calculatePizzaCost(Map<String, Double> pizzaIngredients) {
        return pizzaIngredients.values().stream().mapToDouble(Double::doubleValue).sum();
    }

    // Build a default pizza based on pre-defined ingredients
    private static void buildDefaultPizza(String pizzaName, Map<String, Double> pizzaIngredients, Map<String, Double> ingredientCosts) {
        CustomPizzaBuilder customPizzaBuilder = new CustomPizzaBuilder();
        PizzaDirector director = new PizzaDirector(customPizzaBuilder);

        System.out.printf("Building %s pizza...%n", pizzaName);
        for (String ingredientName : pizzaIngredients.keySet()) {
            if (ingredientCosts.containsKey(ingredientName)) {
                Ingredient newIngredient = new Ingredient(ingredientName, ingredientCosts.get(ingredientName));
                director.addIngredient(newIngredient);
            } else {
                System.out.printf("Ingredient '%s' for %s pizza not found in ingredients list.%n", ingredientName, pizzaName);
                return;
            }
        }

        Pizza pizza = director.constructPizza();
        pizza.displayPizza();
    }
}
