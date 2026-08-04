#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

class Burger{
    public:
        virtual void prepare() = 0;
        virtual ~Burger() = default;
};


class BasicBurger : public Burger{
    public:
        BasicBurger(){
            cout<<"This is a basic burger";
        }
        void prepare(){
            cout<<"A basic burger is being prepared";
        }
};

class StandardBurger : public Burger{
    public:
        StandardBurger(){
            cout<<"This is a standard burger";
        }
        void prepare(){
            cout<<"A Standard burger is being prepared";
        }
};

class PremiumBurger : public Burger{
    public:
        PremiumBurger(){
            cout<<"This is a premium burger";
        }
        void prepare(){
            cout<<"A Premium burger is being prepared";
        }
};

class BurgerFactory{
    Burger* myBurger;
    public:
    Burger* createBurger(string type){
        transform(type.begin(), type.end(), type.begin(), ::toupper);
        if(type  == "BASIC"){
            return new BasicBurger();
        }else if(type == "STANDARD"){
            return new StandardBurger();
        }else if(type == "PREMIUM"){
            return new PremiumBurger();
        }
        return new BasicBurger();
    }
};

int main(){
    BurgerFactory* factory = new BurgerFactory();
    Burger* myBurger = factory->createBurger("basic");

    return 0;
}