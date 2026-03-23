#include <iostream>
using namespace std;


class Book {
protected:
    string title;
    string author;
    string publisher;

public:
    // Constructor
    Book(string t, string a, string p) {
        title = t;
        author = a;
        publisher = p;
    }

    // Display function
    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
    }
};


class FictionBook : public Book {
private:
    string genre;
    string protagonist;

public:
    // Constructor
    FictionBook(string t, string a, string p, string g, string pro)
        : Book(t, a, p) {   // calling base class constructor
        genre = g;
        protagonist = pro;
    }

    // Display function
    void display() {
        // Call base class display
        Book::display();
        cout << "Genre: " << genre << endl;
        cout << "Protagonist: " << protagonist << endl;
    }
};

// Main function
int main() {
    FictionBook fb("Harry Potter", "J.K. Rowling", "Bloomsbury", "Fantasy", "Harry Potter");

    cout << "📖 Fiction Book Details:\n";
    fb.display();

    return 0;
}
