#include <iostream>
#include "Flyable.cpp"
#include "Talkable.cpp"
#include "Walkable.cpp"


class Robot{
    Flyable *fly;
    Talkable *talk;
    Walkable *walk;

    public:
    Robot(Flyable *fly, Talkable *talk, Walkable *walk){
        this->fly = fly;
        this->talk = talk;
        this->walk = walk;
    }

    virtual void projection() = 0;
    virtual ~Robot() = default;



};