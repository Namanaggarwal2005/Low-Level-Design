#include <iostream>
using namespace std;

class PaymentStrategy{
    public:
        virtual void pay() = 0;
};


class NetBanking : public PaymentStrategy{
    public:
        void pay(){
            cout<<"Pay Using net banking";
        }
};

class UPI : public PaymentStrategy{
    public:
        void pay(){
            cout<<"Pay Using UPI";
        }
};

class Credit : public PaymentStrategy{
    public:
        void pay(){
            cout<<"Pay Using credit card";
        }
};