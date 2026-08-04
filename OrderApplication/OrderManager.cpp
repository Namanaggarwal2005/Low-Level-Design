#include <iostream>
#include <vector>
#include "Order.cpp"

using namespace std;

class OrderManager {
private:
    vector<Order> orders;

    static OrderManager* instance;

    OrderManager() {}

public:
    // Singleton
    static OrderManager* getInstance() {
        if (instance == nullptr) {
            instance = new OrderManager();
        }
        return instance;
    }

    // Add Order
    void addOrder(const Order& order) {
        orders.push_back(order);
    }

    // Get Order by ID
    Order* getOrderById(int id) {
        for (auto& order : orders) {
            if (order.getId() == id) {
                return &order;
            }
        }
        return nullptr;
    }

    // Remove Order
    bool removeOrder(int id) {
        for (auto it = orders.begin(); it != orders.end(); ++it) {
            if (it->getId() == id) {
                orders.erase(it);
                return true;
            }
        }
        return false;
    }

    // Update Payment Strategy
    bool updatePaymentStrategy(int id, PaymentStrategy* payment) {
        Order* order = getOrderById(id);

        if (order == nullptr)
            return false;

        order->setPaymentStrategy(payment);
        return true;
    }

    // Get all orders of a user
    vector<Order*> getOrdersByUser(int userId) {

        vector<Order*> result;

        for (auto& order : orders) {
            if (order.getUser()->getId() == userId) {
                result.push_back(&order);
            }
        }

        return result;
    }

    // Get all orders of a restaurant
    vector<Order*> getOrdersByRestaurant(int restaurantId) {

        vector<Order*> result;

        for (auto& order : orders) {
            if (order.getRestaurant()->getId() == restaurantId) {
                result.push_back(&order);
            }
        }

        return result;
    }

    // Display all orders
    void displayOrders() {

        if (orders.empty()) {
            cout << "No Orders Found.\n";
            return;
        }

        for (auto& order : orders) {
            order.displayOrder();
            cout << "---------------------------------\n";
        }
    }

    // Total orders
    int totalOrders() const {
        return orders.size();
    }

    // Get all orders
    const vector<Order>& getAllOrders() const {
        return orders;
    }
};

// Static member initialization
OrderManager* OrderManager::instance = nullptr;