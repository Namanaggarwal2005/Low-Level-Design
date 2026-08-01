#include <iostream>
using namespace std;


class Payment {
public:
    virtual void pay(double amount) = 0; 
};

// Derived class
class CreditCardPayment : public Payment {
public:
    void pay(double amount) override {
        cout << "Paid ₹" << amount << " using Credit Card\n";
    }
};

class UPIPayment : public Payment {
public:
    void pay(double amount) override {
        cout << "Paid ₹" << amount << " using UPI\n";
    }
};

int main() {
    Payment* p1 = new CreditCardPayment();
    Payment* p2 = new UPIPayment();

    p1->pay(1500);
    p2->pay(500);

    delete p1;
    delete p2;

    return 0;
}