#include<bits/stdc++.h>
using namespace std;
class document{
    public:
    virtual void creation()=0;
    virtual ~document()=default;
};
class PDF:public document{
    public:
    void creation(){
        cout<<"Created a PDF file";
    }
}; 
class HTML:public document{
    public:
    void creation(){
        cout<<"created a HTML file"<<endl;
    }
};
class Word:public document{
    public:
    void creation(){
        cout<<"created a Word file"<<endl;
    }
};
class Factory{
    public:
    document* creatDocument(string s){
        if(s=="HTML"){
            return new HTML();
        }else if(s=="PDF"){
            return new PDF();
        }else if(s=="Word"){
            return new Word();
        }else {
            return NULL;
        }
    }
};
int main(){
    Factory* f= new Factory();
    document* w=f->creatDocument("Word");
    document *html=f->creatDocument("HTML");
    w->creation();
    html->creation();
    return 0;
}