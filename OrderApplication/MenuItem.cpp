#include<iostream>
#include<string>
using namespace std;


class MenuItem {
private:
    int code;
    string name;
    double price;

public:
    // Setters
    void setCode(int code) {
        this->code = code;
    }

    void setName(const string& name) {
        this->name = name;
    }

    void setPrice(double price) {
        this->price = price;
    }

    
    int getCode() const {
        return code;
    }

    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }
};