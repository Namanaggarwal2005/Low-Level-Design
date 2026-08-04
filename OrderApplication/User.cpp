#include <iostream>
#include <string>
#include "Cart.cpp"

using namespace std;

class User {
private:
    int id;
    string name;
    string address;
    Cart cart;

public:
    // Constructors
    User() {}

    User(int id, const string& name, const string& address) {
        this->id = id;
        this->name = name;
        this->address = address;
    }

    // Getters
    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    string getAddress() const {
        return address;
    }

    Cart& getCart() {
        return cart;
    }

    // Setters
    void setId(int id) {
        this->id = id;
    }

    void setName(const string& name) {
        this->name = name;
    }

    void setAddress(const string& address) {
        this->address = address;
    }

    void setCart(const Cart& cart) {
        this->cart = cart;
    }

    // Utility
    void displayUser() const {
        cout << "User ID : " << id << endl;
        cout << "Name    : " << name << endl;
        cout << "Address : " << address << endl;
    }
};