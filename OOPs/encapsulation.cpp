#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;    // Hidden data

public:
    // Constructor
    BankAccount(double initialBalance) {
        balance = initialBalance;
    }

    // Public method to deposit money
    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
    }

    // Public method to withdraw money
    void withdraw(double amount) {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient balance\n";
    }

    // Getter
    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account(1000);

    account.deposit(500);
    account.withdraw(200);

    cout << "Balance: " << account.getBalance() << endl;

    // account.balance = 100000;   //  Error: balance is private
}