#include <iostream>
using namespace std;


class Position {
protected:
    int x, y, z;

public:
    // Constructor
    Position(int xVal, int yVal, int zVal) {
        x = xVal;
        y = yVal;
        z = zVal;
    }

    void displayPosition() {
        cout << "Position (x, y, z): (" << x << ", " << y << ", " << z << ")" << endl;
    }
};


class Health {
protected:
    int health;

public:
    // Constructor
    Health(int h) {
        health = h;
    }

    void displayHealth() {
        cout << "Health: " << health << endl;
    }
};

// Derived class (Multiple Inheritance)
class Character : public Position, public Health {
private:
    string name;

public:
    // Constructor
    Character(string n, int xVal, int yVal, int zVal, int h)
        : Position(xVal, yVal, zVal), Health(h) {
        name = n;
    }

    void display() {
        cout << "Character: " << name << endl;
        displayPosition();   // from Position
        displayHealth();     // from Health
    }
};

// Main function
int main() {
    Character hero("Knight", 10, 20, 5, 100);

    cout << "🚀 Spawning Character...\n\n";
    hero.display();

    return 0;
}
