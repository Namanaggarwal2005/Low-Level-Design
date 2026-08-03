#include<iostream>
using namespace std;


class Walkable{
    public:
        virtual void fly() = 0;
        virtual ~Walkable() = default;
};

class NormalFlying : public Walkable{
    public:
        void fly() override{
            cout<<"I fly Normally";
        }
};

class NoFly : public Walkable{
    public:
        void fly() override{
            cout<<"I cannot fly at all";
        }
};