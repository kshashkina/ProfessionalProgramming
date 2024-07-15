#include <iostream>
#include <concepts>
#include <print>

template<typename T>
concept PricedItem = requires(T t) {
{ t.getCoefficient() } -> std::convertible_to<double>;
{ t.getBasePrice() } -> std::convertible_to<double>;
};

template<size_t PRIORITY>
class PricePresenter {
public:
    template<PricedItem T1, PricedItem T2>
    void printTotalPrice(const T1& obj1, const T2& obj2) const {
        double totalPrice = PRIORITY * obj1.getCoefficient() * obj1.getBasePrice() +
                            obj2.getCoefficient() * obj2.getBasePrice();
        std::println("Total Price: {}", totalPrice);
    }
};

class Milk {
public:
    double getCoefficient() const { return 1.5; }
    double getBasePrice() const { return 2.0; }
};

class Cookies {
public:
    double getCoefficient() const { return 2.0; }
    double getBasePrice() const { return 3.0; }
};

class Pineapple {
public:
    double getCoefficient() const { return 1.2; }
    double getBasePrice() const { return 4.0; }
};

int main() {
    Milk milk;
    Cookies cookies;
    Pineapple pineapple;

    PricePresenter<3> presenter;

    presenter.printTotalPrice(milk, cookies);
    presenter.printTotalPrice(cookies, pineapple);
    presenter.printTotalPrice(milk, pineapple);

    return 0;
}
