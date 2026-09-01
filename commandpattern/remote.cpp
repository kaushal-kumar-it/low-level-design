#include<iostream>
using namespace std;
class remote{
    public:
    void turnOnLight(){
     
        cout<<"Lights are turned on "<<endl;
    }
    void turnOnFan(){
        cout<<"fan is turned on "<<endl;
    }
    void turnOffLight(){
     
        cout<<"Lights are turned off "<<endl;
    }
    void turnOffFan(){
     
        cout<<"fan is turned off "<<endl;
    }
};
class Command{
    public:
    remote* t;
    virtual void execute()=0;
};
class TurnOnLight:public Command{
    public:
    TurnOnLight(remote *p){
        t=p;
    }
    void execute(){
        t->turnOnLight();
    }
};
class TurnOffLight:public Command{
    public:
    TurnOffLight(remote *p){
        t=p;
    }
    void execute(){
        t->turnOffLight();
    }
};
class TurnOnFan:public Command{
    public:
    TurnOnFan(remote *p){
        t=p;
    }
    void execute(){
        t->turnOnFan();
    }
};
class TurnOffFan:public Command{
    public:
    TurnOffFan(remote *p){
        t=p;
    }
    void execute(){
        t->turnOffFan();
    }
};

class Button{
    Command* c;
    public:
    void setCommand(Command *c){
        this->c=c;
    }
    void click(){
        c->execute();
    }
};
int main(){
    remote *r=new remote();
    TurnOnLight *t=new TurnOnLight(r);
    TurnOffFan *x=new TurnOffFan(r);
    Button *but=new Button();
    but->setCommand(t);
    but->click();
    but->setCommand(x);
    but->click();
    return 0;
}