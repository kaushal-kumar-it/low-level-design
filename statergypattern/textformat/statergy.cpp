#include<iostream>
#include<string.h>
using namespace std;
class Textformat{
    
    public:
    virtual void format(string s)=0;
    virtual ~Textformat()=default;
};
class PlainTextFormat: public Textformat{
    public:
    void format(string s){
        cout<<s<<endl;
    }
};
class HTMLFormat:public Textformat{
    public:
    void format(string s){
        cout<<"<html><body>"<<s<<"</body></html>"<<endl;
    }
};
class MarkDownFormat:public Textformat{
    public:
    void format(string s){
        cout<<"**"<<s<<"**"<<endl;
    }
};
class TextEditor{
    Textformat* p;
    public:
    void setTextFormat(Textformat* t){
        delete p;
        this->p=t;
    }
    void format(string s){
        p->format(s);
    }
};
int main(){
    TextEditor *t=new TextEditor();
    t->setTextFormat(new  HTMLFormat());
    t->format("Hello Kaushal");
    t->setTextFormat(new PlainTextFormat());
    t->format("Hello Kaushal");
    t->setTextFormat(new MarkDownFormat());
    t->format("KAUSHAL");
}