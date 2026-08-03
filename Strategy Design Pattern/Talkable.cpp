#include<iostream>
using namespace std;


class Talkable{
    public:
        virtual void talk() = 0;
        virtual ~Talkable() = default;
};

class NormalTalk : public Talkable{
    public:
        void talk() override{
            cout<<"I Talk in the normal way";
        }
};

class NoTalk : public Talkable{
    public:
        void talk() override{
            cout<<"......";
        }
};


