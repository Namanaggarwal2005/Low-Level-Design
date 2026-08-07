#include<iostream>
#include<string>
using namespace std;



class ICharacter{
    public:
        virtual void getAbilities() = 0;
        ~ICharacter() = default;
};

class Mario : public ICharacter{
    public:
        void getAbilities(){
            cout<<"I can run ";
        }
};

class Decorator : public ICharacter{
    protected:
    ICharacter* character;
    public:
        virtual void getAbilities() = 0;
        virtual ~Decorator() = default;

};

class HeightUP : public Decorator{
    public:
        HeightUP(ICharacter* character){
            this->character = character;
        }
        void getAbilities(){
            character->getAbilities() ;
            cout<<"Faster";
        }
};


class Shooter : public Decorator{
    public:
        Shooter(ICharacter* character){
            this->character = character;
        }
        void getAbilities(){
            character->getAbilities() ;
            cout<<" and can shoot";
        }
};


int main(){
    ICharacter* mario = new Mario();

    mario = new HeightUP(mario);
    mario = new Shooter(mario);

    mario->getAbilities();

    delete mario;
}
