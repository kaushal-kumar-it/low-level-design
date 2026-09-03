#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Mediator;
class User{
    string name;
    Mediator *m;
    public:
    User(string n,Mediator *m){
        name=n;
        this->m=m;
    }
    string getName(){
        return name;
    }
    void recieveMsg(string msg,User *u){
        cout<<"User "<<u->getName()<<" send msg :"<<msg<<endl;
    }
    void sendMsg(string msg);
   
};
class Mediator{
    vector<User*>users={};
    public:
    void addUser(User* u){
        users.push_back(u);
    }
    void sendMsg(string msg ,User* u){
        for(auto user:users){
            if(user!=u){
                user->recieveMsg(msg,u);
            }
        }
    }
};
void User::sendMsg(string msg){
        cout<<name<<" sending msg to everyone "<<msg<<endl;
        m->sendMsg(msg,this);
}
int main(){
    Mediator *mediator=new Mediator();
    User *kaushal =new User("kaushal",mediator);
    User *amit=new User("amit",mediator);
    User *neha=new User("neha",mediator);
    User *dipesh=new User("dipesh",mediator);
    mediator->addUser(kaushal);
    mediator->addUser(amit);
    mediator->addUser(neha);
    mediator->addUser(dipesh);
    dipesh->sendMsg("hi everyone");
    kaushal->sendMsg("hi dipesh and everyone");
    return 0;

}