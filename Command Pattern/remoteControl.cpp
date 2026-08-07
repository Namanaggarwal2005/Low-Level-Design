#include<iostream>
#include<string>
#include<vector>
using namespace std;


class ICommand{
    public:
        virtual void execute() = 0;
        virtual void undo() = 0;
        virtual ~ICommand() = default;
};

class Light{
    public:
        void on(){
            cout<<"Light is on";
        }
        void off(){
            cout<<"Light is off";
        }
};

class LightCommand : public ICommand{
    Light* light;
    public:
        LightCommand(Light* light){
            this->light = light;
        }
        void execute(){
            light->on();
        }
        void undo(){
            light->off();
        }
};

class RemoteControl{
    static const int buttons = 4;
    ICommand* commands[buttons];
    bool isPressed[buttons];

    public:
        RemoteControl(){
            for(int i=0; i<buttons; i++){
                commands[i] = NULL;
                isPressed[i] = false;
            }
        }
        void setCommand(int i,ICommand* command){
            if(i < 0 || i >= buttons){
                cout<<"Invalid button\n";
                return;
            }
            commands[i] = command;
        }
        void pressButton(int i){
            if(i < 0 || i >= buttons){
                cout<<"Invalid button\n";
                return;
            }
            if(!commands[i]){
                cout<<"First Set the button then press it ";
                return;
            }
            if(isPressed[i] == false){
                commands[i]->execute();
            }else{
                commands[i]->undo();
            }
            isPressed[i] = !isPressed[i];
            return;
        }

};

int main(){

    return 0;
}