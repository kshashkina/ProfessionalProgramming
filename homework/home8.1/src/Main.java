interface PricedItem {
    double getCoefficient();
    double getBasePrice();
}

class PricePresenter<T1 extends PricedItem, T2 extends PricedItem> {
    private final int PRIORITY;

    public PricePresenter(int priority) {
        this.PRIORITY = priority;
    }

    public void printTotalPrice(T1 obj1, T2 obj2) {
        double totalPrice = PRIORITY * obj1.getCoefficient() * obj1.getBasePrice() +
                obj2.getCoefficient() * obj2.getBasePrice();
        System.out.println("Total Price: " + totalPrice);
    }
}

class Milk implements PricedItem {
    public double getCoefficient() { return 1.5; }
    public double getBasePrice() { return 2.0; }
}

class Cookies implements PricedItem {
    public double getCoefficient() { return 2.0; }
    public double getBasePrice() { return 3.0; }
}

class Pineapple implements PricedItem {
    public double getCoefficient() { return 1.2; }
    public double getBasePrice() { return 4.0; }
}

public class Main {
    public static void main(String[] args) {
        Milk milk = new Milk();
        Cookies cookies = new Cookies();
        Pineapple pineapple = new Pineapple();

        PricePresenter<PricedItem, PricedItem> presenter = new PricePresenter<>(3);

        presenter.printTotalPrice(milk, cookies);
        presenter.printTotalPrice(cookies, pineapple);
        presenter.printTotalPrice(milk, pineapple);   
    }
}
