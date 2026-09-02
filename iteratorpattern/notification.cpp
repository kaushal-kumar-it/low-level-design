#include<iostream>
#include<string.h> 
#include<vector>
using namespace std;
template<typename T>
class Iterator{
    public:
    virtual bool hasNext()=0;
    virtual T next()=0;
    virtual ~Iterator()=default;
};
class noti{
    public:
    string noti;
    virtual void printNoti()=0;
    virtual ~noti()=default;
};
class Email:public noti{
    public:
    Email(string n ){
        noti=n;
    }
    void printNoti(){
        cout<<"Email Nofitification: "<<noti<<endl;
    }
};
class SmsNoti:public noti{
    public:
    SmsNoti(string n ){
        noti=n;
    }
    void printNoti(){
        cout<<"Sms Nofitification: "<<noti;
    }
};
class NotificationCollections{
    vector<noti*>notifications;
    public:
    void addNotifications(noti *t){
        notifications.push_back(t);
    }
    class notiInterator :public Iterator<noti*>{
        vector<noti*>notification;
        int idx=0;
        public:
        notiInterator(vector<noti*>n){
            notification=n;
        }
        bool hasNext() override{
            return idx<(int)notification.size();
        }
        noti* next() override{
            return notification[idx++];
        }
    };
    Iterator<noti*>* getIterator(){
        return new notiInterator(notifications);
    }
    
};
int main(){
    NotificationCollections* n=new NotificationCollections();
    n->addNotifications(new Email("hi this is my msg"));
    n->addNotifications(new Email("second msg"));
    n->addNotifications(new SmsNoti("first sms"));
    Iterator<noti*>* it=n->getIterator();
    while(it->hasNext()){
        noti* n=it->next();
        n->printNoti();
    }
    return 0;

}