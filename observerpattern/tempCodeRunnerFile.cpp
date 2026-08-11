#include<bits/stdc++.h>
using namespace std;
class Device{
    public:
    string name;
    virtual void update(float temp);
};
class weather{
    public:
    float temp;
    virtual void setTemp(float t);
    virtual void notify();
    virtual void addDevice(Device* d);
    virtual void removeDevice(Device* d);
};
class weatherstation:public weather{
    unordered_map<Device*,int>devices;
    public:
    void setTemp(float t){
        temp=t;
        notify();
    }
    void notify(){
        for(auto i:devices){
            i.first->update(temp);
        }
    }
    void addDevice(Device* d){
        devices[d]++;
    }
    void removeDevice(Device* d){
        devices.erase(d);
    }
};
class mobile:public Device{
    public:
    mobile(string n){
        name=n;
    }
    void update(float temp){
        cout<<"temp on the mobile phone"<<name<<"is"<<temp<<endl;
    }
};
class computer:public Device{
    public:
    computer(string n){
        name=n;
    }
    void update(float temp){
        cout<<"temp on the computer"<<name<<"is"<<temp<<endl;
    }
};
int main(){
    weatherstation* w=new weatherstation();
    Device* m=new mobile("kaushal");
    Device* c=new computer("kkpc");
    w->addDevice(m);
    w->addDevice(c);
    w->setTemp(20);
    w->setTemp(22);
    w->removeDevice(m);
    w->setTemp(848);
    return 0;
}