#include <bits/stdc++.h>
using namespace std;

class snapshot {
private:
    string data;

    snapshot(string d) : data(d) {}

    friend class Testbook;
};

class master {
private:
    stack<snapshot*> st;

public:
    void save(snapshot* s) {
        st.push(s);
    }

    snapshot* undo() {
        if (st.empty())
            return nullptr;

        st.pop();
        snapshot* s = st.top();
        
        return st.top();
    }
};

class Testbook {
private:
    master* m;
    string text;

public:
    Testbook(master* m1) {
        m = m1;
    }

    void write(string t) {
        text = t;
    }

    void show() {
        cout << text << endl;
    }

    void save() {
        m->save(new snapshot(text));
    }

    void undo() {
        snapshot* s = m->undo();

        if (s) {
            text = s->data;
            delete s;
        }
    }
};

int main() {
    master* m = new master();
    Testbook* t = new Testbook(m);

    t->write("hello how are you");
    t->save();
    t->show();

    t->write("dipesh rand hai");
    t->save();
    t->show();

    t->undo();
    t->show();

    t->undo();
    t->show();

    delete t;
    delete m;

    return 0;
}