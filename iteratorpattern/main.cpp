#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual T next() = 0;
    virtual ~Iterator() = default;
};

class Books {
    string title;

public:
    Books(string title) {
        this->title = title;
    }

    void getTitle() {
        cout << "Title: " << title << endl;
    }
};

class BooksCollections {
    vector<Books*> book;

public:
    void addBook(Books* p) {
        book.push_back(p);
    }

    class BookIterator : public Iterator<Books*> {
        int idx = 0;
        vector<Books*> book;

    public:
        BookIterator(const vector<Books*>& b) {
            this->book = b;
        }

        bool hasNext() override {
            return idx < (int)book.size();
        }

        Books* next() override {
            return book[idx++];
        }
    };

    Iterator<Books*>* getIterator() {
        return new BookIterator(book);
    }
};

int main() {
    BooksCollections* books = new BooksCollections();

    books->addBook(new Books("science book"));
    books->addBook(new Books("maths book"));
    books->addBook(new Books("environment book"));

    Iterator<Books*>* it = books->getIterator();

    while (it->hasNext()) {
        Books* b = it->next();
        b->getTitle();
    }

    return 0;
}