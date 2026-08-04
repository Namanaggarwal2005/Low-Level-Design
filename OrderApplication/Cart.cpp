#include <iostream>
#include <vector>
#include "Restaurant.cpp"
#include "MenuItem.cpp"

using namespace std;

class CartItem {
private:
    MenuItem item;
    int quantity;

public:
    CartItem() : quantity(0) {}

    CartItem(const MenuItem& item, int quantity) {
        this->item = item;
        this->quantity = quantity;
    }

    // Getters
    MenuItem getItem() const {
        return item;
    }

    int getQuantity() const {
        return quantity;
    }

    // Setters
    void setItem(const MenuItem& item) {
        this->item = item;
    }

    void setQuantity(int quantity) {
        this->quantity = quantity;
    }

    double getSubtotal() const {
        return item.getPrice() * quantity;
    }
};

class Cart {
private:
    Restaurant* rs;
    vector<CartItem> items;

public:
    Cart() {
        rs = nullptr;
    }

    Cart(Restaurant* restaurant) {
        rs = restaurant;
    }

    // Getters
    Restaurant* getRestaurant() const {
        return rs;
    }

    const vector<CartItem>& getItems() const {
        return items;
    }

    // Setters
    void setRestaurant(Restaurant* restaurant) {
        rs = restaurant;
    }

    // Add item to cart
    void addToCart(const MenuItem& item, int quantity = 1) {

        // If item already exists, increase quantity
        for (auto& cartItem : items) {
            if (cartItem.getItem().getCode() == item.getCode()) {
                cartItem.setQuantity(cartItem.getQuantity() + quantity);
                return;
            }
        }

        // Otherwise add a new item
        items.push_back(CartItem(item, quantity));
    }

    // Remove item completely
    bool removeFromCart(int code) {

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
                    removeFromCart(code);
                } else {
                    cartItem.setQuantity(quantity);
                }

                return true;
            }
        }

        return false;
    }

    // Clear cart
    void clearCart() {
        items.clear();
    }

    // Total price
    double calculateTotal() const {

        double total = 0;

        for (const auto& cartItem : items) {
            total += cartItem.getSubtotal();
        }

        return total;
    }

    // Number of distinct items
    int getItemCount() const {
        return items.size();
    }

    // Is cart empty?
    bool isEmpty() const {
        return items.empty();
    }

    // Display cart
    void displayCart() const {

        if (rs != nullptr) {
            cout << "Restaurant : " << rs->getName() << endl;
        }

        cout << "--------------------------------------\n";

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

        cout << "--------------------------------------\n";
        cout << "Grand Total : ₹" << calculateTotal() << endl;
    }
};