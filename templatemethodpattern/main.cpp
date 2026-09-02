#include<iostream>
using namespace std;
class ReportGenerator{
    public:
    void gaterData(){
        cout<<"Gatering Data .... "<<endl;
    }
    void printData(){
        cout<<"Printing Data ..."<<endl;
    }
    void templateFunction(){
        gaterData();
        processData();
        formatData();
        printData();
    }
    virtual void processData()=0;
    virtual void formatData()=0;
};
class SalesReport:public ReportGenerator{
    public:
    void processData(){
        cout<<"processing the sales data"<<endl;
    }
    void formatData(){
        cout<<"Formatting the sales Data "<<endl;
    }
};
class AttendenceReport:public ReportGenerator{
    public:
    void processData(){
        cout<<"processing the Attendence data"<<endl;
    }
    void formatData(){
        cout<<"Formatting the Attendence Data "<<endl;
    }
};
int main(){
    ReportGenerator* r=new SalesReport();
    r->templateFunction();
    ReportGenerator* c=new AttendenceReport();
    c->templateFunction();
    return 0;
}