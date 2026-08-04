#include<iostream>
#include<vector>
#include<string>
#include "./MenuItem.cpp"
using namespace std;

class Restaurant{
    int id;
    string name;
    string order;
    string location;
    vector<MenuItem>menu;

    public:
    Restaurant() {}

    Restaurant(int id, const string& name, const string& order, const string& location) {
        this->id = id;
        this->name = name;
        this->order = order;
        this->location = location;
    }

    // Setters
    void setId(int id) {
        this->id = id;
    }

    void setName(const string& name) {
        this->name = name;
    }

    void setOrder(const string& order) {
        this->order = order;
    }

    void setMenu(const vector<MenuItem>& menu) {
        this->menu = menu;
    }

    void setLocation(const string& location) {
        this->location = location;
    }

    string getLocation() const {
        return location;
    }
    
    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    string getOrder() const {
        return order;
    }

    const vector<MenuItem>& getMenu() const {
        return menu;
    }

    // Menu Operations
    void addMenuItem(const MenuItem& item) {
        menu.push_back(item);
    }

    void removeMenuItem(int code) {
        for (auto it = menu.begin(); it != menu.end(); it++) {
            if (it->getCode() == code) {
                menu.erase(it);
                break;
            }
        }
    }

    void displayMenu() const {
        cout << "Menu of " << name << ":\n";
        for (const auto& item : menu) {
            cout << item.getCode() << " "
                 << item.getName() << " ₹"
                 << item.getPrice() << endl;
        }
    }
};