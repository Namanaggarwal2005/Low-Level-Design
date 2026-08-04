#include<iostream>
using namespace std;


class Singleton{
    private:
    static Singleton* instance;
    Singleton(){
        cout<<"A singleton object created";
    }

    public:
    Singleton* getInstance(){
        return instance;
    }
};

Singleton* Singleton::instance = new Singleton();

int main(){

}