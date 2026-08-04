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

class BasicWheatBurger : public Burger{
    public:
        BasicWheatBurger(){
            cout<<"This is a basic wheat burger";
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
class StandardWheatBurger : public Burger{
    public:
        StandardWheatBurger(){
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


class PremiumWheatBurger : public Burger{
    public:
        PremiumWheatBurger(){
            cout<<"This is a premium burger";
        }
        void prepare(){
            cout<<"A Premium burger is being prepared";
        }
};


class BurgerFactory{
    Burger* myBurger;
    public:
    virtual Burger* createBurger(string s) = 0;
};

class KingBurgerFactory : public BurgerFactory{
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
        return NULL;
    }
};

class SinghBurgerFactory : public BurgerFactory{
    public:
    Burger* createBurger(string type){
        transform(type.begin(), type.end(), type.begin(), ::toupper);
        if(type  == "BASIC"){
            return new BasicWheatBurger();
        }else if(type == "STANDARD"){
            return new StandardWheatBurger();
        }else if(type == "PREMIUM"){
            return new PremiumWheatBurger();
        }
        return NULL;
    }
};



int main(){
    
    return 0;
}