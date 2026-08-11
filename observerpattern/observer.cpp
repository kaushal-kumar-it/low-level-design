#include<bits/stdc++.h>
using namespace std;
class Device{
    public:
    string name;
    virtual void update(float temp)=0;
};
class weather{
    public:
    float temp;
    virtual void setTemp(float t)=0;
    virtual void notify()=0;
    virtual void addDevice(Device* d)=0;
    virtual void removeDevice(Device* d)=0;
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
        cout<<"temp on the mobile phone "<<name<<" is "<<temp<<endl;
    }
};
class computer:public Device{
    public:
    computer(string n){
        name=n;
    }
    void update(float temp){
        cout<<"temp on the computer "<<name<<" is "<<temp<<endl;
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