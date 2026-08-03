#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Product{
    public:
    int price;
    string name;

    
        Product(int price, string name){
            this->price = price;
            this->name  = name;
        }
};


class ShoppingCart{
    vector<Product*> products;
    public:
        void addProduct(Product* myProduct){
            products.push_back(myProduct);
        }
        int calculateTotal(){
            int sum = 0;
            for(int i=0; i<products.size(); i++){
                sum += products[i]->price;
            }
            return sum;
        }
};

class SaveToDB{
    ShoppingCart * cart;
    public:
        virtual void save() = 0;

};

class SaveToSQL : public SaveToDB{
    public:
        void save(){
            // Save to SQL
        }
};

class SaveToMongo : public SaveToDB{
    public:
        void save(){
            // Save to Mongo
        }
};

class SaveToFile : public SaveToDB{
    public:
        void save(){
            // Save to File
        }
};

class ShoppingCartInvoice{
    public:
        void printInvoice(ShoppingCart* myCart){
            // Print invoice
        }
};


int main(){

    return 0;
}

