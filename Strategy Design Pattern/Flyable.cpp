#include<iostream>
using namespace std;


class Flyable{
    public:
        virtual void talk() = 0;
        virtual ~Flyable() = default;
};

class NormalTalk : public Flyable{
    public:
        void talk() override{
            cout<<"I Talk in the normal way";
        }
};

class NoTalk : public Flyable{
    public:
        void talk() override{
            cout<<"......";
        }
};