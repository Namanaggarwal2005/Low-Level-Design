#include <iostream>
#include <string>
#include <vector>

using namespace std;

//--------------------------------------------
// Product
//--------------------------------------------
class Product {
private:
    string name;
    int price;

public:
    Product(const string& name, int price)
        : name(name), price(price) {}

    string getName() const {
        return name;
    }

    int getPrice() const {
        return price;
    }
};

//--------------------------------------------
// Shopping Cart
//--------------------------------------------
class ShoppingCart {
private:
    vector<Product*> products;

public:
    void addProduct(Product* product) {
        products.push_back(product);
    }

    int calculateTotal() const {
        int sum = 0;

        for (auto product : products)
            sum += product->getPrice();

        return sum;
    }

    const vector<Product*>& getProducts() const {
        return products;
    }
};

//--------------------------------------------
// Repository Interface
//--------------------------------------------
class CartRepository {
public:
    virtual void save(const ShoppingCart& cart) = 0;
    virtual ~CartRepository() = default;
};

//--------------------------------------------
// SQL Repository
//--------------------------------------------
class SQLRepository : public CartRepository {
public:
    void save(const ShoppingCart& cart) override {

        cout << "\nSaving Cart to SQL Database\n";

        for (auto product : cart.getProducts()) {
            cout << product->getName()
                 << " : Rs. "
                 << product->getPrice()
                 << endl;
        }

        cout << "Total = Rs. "
             << cart.calculateTotal()
             << endl;
    }
};

//--------------------------------------------
// Mongo Repository
//--------------------------------------------
class MongoRepository : public CartRepository {
public:
    void save(const ShoppingCart& cart) override {

        cout << "\nSaving Cart to MongoDB\n";

        for (auto product : cart.getProducts()) {
            cout << product->getName()
                 << " : Rs. "
                 << product->getPrice()
                 << endl;
        }

        cout << "Total = Rs. "
             << cart.calculateTotal()
             << endl;
    }
};

//--------------------------------------------
// File Repository
//--------------------------------------------
class FileRepository : public CartRepository {
public:
    void save(const ShoppingCart& cart) override {

        cout << "\nSaving Cart to File\n";

        for (auto product : cart.getProducts()) {
            cout << product->getName()
                 << " : Rs. "
                 << product->getPrice()
                 << endl;
        }

        cout << "Total = Rs. "
             << cart.calculateTotal()
             << endl;
    }
};

//--------------------------------------------
// Invoice Printer
//--------------------------------------------
class ShoppingCartInvoice {
public:
    void printInvoice(const ShoppingCart& cart) {

        cout << "\n========== INVOICE ==========\n";

        for (auto product : cart.getProducts()) {
            cout << product->getName()
                 << " : Rs. "
                 << product->getPrice()
                 << endl;
        }

        cout << "-----------------------------\n";
        cout << "Total : Rs. "
             << cart.calculateTotal()
             << endl;

        cout << "=============================\n";
    }
};

//--------------------------------------------
// Main
//--------------------------------------------
int main() {

    Product p1("Laptop", 60000);
    Product p2("Mouse", 1500);
    Product p3("Keyboard", 2500);

    ShoppingCart cart;

    cart.addProduct(&p1);
    cart.addProduct(&p2);
    cart.addProduct(&p3);

    ShoppingCartInvoice invoice;
    invoice.printInvoice(cart);

    CartRepository* repository;

    repository = new SQLRepository();
    repository->save(cart);
    delete repository;

    repository = new MongoRepository();
    repository->save(cart);
    delete repository;

    repository = new FileRepository();
    repository->save(cart);
    delete repository;

    return 0;
}