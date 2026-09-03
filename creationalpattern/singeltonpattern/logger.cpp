#include<bits/stdc++.h>
#include<chrono>
using namespace std;
class Logger{
    static Logger* l;
    public:
    static Logger *getInstance(){
        if(l==NULL){
           Logger *log=new Logger();
           l=log; 
        }
        return &l;
    }
    void info(string msg){
        auto x=chrono::system_clock::now();
        auto t = chrono::system_clock::to_time_t(x);
        cout<<"Info: "<<msg << " " << ctime(&t);
    }
    void warn(string msg){
        cout<<"Warn: "<<msg<<endl;
    }
    void error(string msg){
        cout<<"Error :"<<msg<<endl;
    }
};
Logger* Logger::l = nullptr;
int main()
{
    Logger *l=Logger::getInstance();
    l->info("this is the info");
    l->warn("cpu usage is too high");
    l->error("a error in our backend");
    Logger *q=Logger::getInstance();
    if(l==q){
        cout<<"hi";
    }
    return 0;
}