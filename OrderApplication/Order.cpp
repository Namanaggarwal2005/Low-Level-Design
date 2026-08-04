#include <iostream>
#include <vector>
#include "Restaurant.cpp"
#include "Cart.cpp"
#include "User.cpp"
#include "PaymentStrategy.cpp"

using namespace std;

class Order {
private:
    int id;
    Restaurant* restaurant;
    User* user;
    vector<CartItem> items;
    PaymentStrategy* paymentStrategy;

public:
    // Constructors
    Order() {
        id = 0;
        restaurant = nullptr;
        user = nullptr;
        paymentStrategy = nullptr;
    }

    Order(int id,
          Restaurant* restaurant,
          User* user,
          const vector<CartItem>& items,
          PaymentStrategy* paymentStrategy) {

        this->id = id;
        this->restaurant = restaurant;
        this->user = user;
        this->items = items;
        this->paymentStrategy = paymentStrategy;
    }

    // Getters
    int getId() const {
        return id;
    }

    Restaurant* getRestaurant() const {
        return restaurant;
    }

    User* getUser() const {
        return user;
    }

    const vector<CartItem>& getItems() const {
        return items;
    }

    PaymentStrategy* getPaymentStrategy() const {
        return paymentStrategy;
    }

    // Setters
    void setId(int id) {
        this->id = id;
    }

    void setRestaurant(Restaurant* restaurant) {
        this->restaurant = restaurant;
    }

    void setUser(User* user) {
        this->user = user;
    }

    void setItems(const vector<CartItem>& items) {
        this->items = items;
    }

    void setPaymentStrategy(PaymentStrategy* paymentStrategy) {
        this->paymentStrategy = paymentStrategy;
    }

    // Add item
    void addItem(const MenuItem& item, int quantity = 1) {

        for (auto& cartItem : items) {
            if (cartItem.getItem().getCode() == item.getCode()) {
                cartItem.setQuantity(cartItem.getQuantity() + quantity);
                return;
            }
        }

        items.push_back(CartItem(item, quantity));
    }

    // Remove item
    bool removeItem(int code) {

        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->getItem().getCode() == code) {
                items.erase(it);
                return true;
            }
        }

        return false;
    }

    // Update quantity
    bool updateQuantity(int code, int quantity) {

        for (auto& cartItem : items) {

            if (cartItem.getItem().getCode() == code) {

                if (quantity <= 0) {
                    return removeItem(code);
                }

                cartItem.setQuantity(quantity);
                return true;
            }
        }

        return false;
    }

    // Total bill
    double calculateTotal() const {

        double total = 0;

        for (const auto& cartItem : items) {
            total += cartItem.getSubtotal();
        }

        return total;
    }

    // Payment
    void makePayment() {

        if (paymentStrategy == nullptr) {
            cout << "No payment strategy selected.\n";
            return;
        }

        paymentStrategy->pay();
    }

    // Display order
    void displayOrder() const {

        cout << "\n========== ORDER ==========\n";

        cout << "Order ID : " << id << endl;

        if (user)
            cout << "Customer : " << user->getName() << endl;

        if (restaurant)
            cout << "Restaurant : " << restaurant->getName() << endl;

        cout << "\nItems\n";
        cout << "------------------------------------------\n";

        for (const auto& cartItem : items) {

            MenuItem item = cartItem.getItem();

            cout << item.getCode()
                 << "  "
                 << item.getName()
                 << "  Qty: "
                 << cartItem.getQuantity()
                 << "  Price: ₹"
                 << item.getPrice()
                 << "  Total: ₹"
                 << cartItem.getSubtotal()
                 << endl;
        }

        cout << "------------------------------------------\n";
        cout << "Grand Total : ₹" << calculateTotal() << endl;
    }
};