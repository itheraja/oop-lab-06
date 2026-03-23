#include <iostream>
using namespace std;


class Character {
protected:
    int health;
    int damage;

public:
    // Constructor
    Character(int h, int d) {
        health = h;
        damage = d;
    }

    // Display function
    void display() {
        cout << "Health: " << health << endl;
        cout << "Damage: " << damage << endl;
    }
};


class Enemy : public Character {
public:
    // Constructor
    Enemy(int h, int d) : Character(h, d) {}

    // Display function
    void display() {
        cout << "👹 Enemy Stats:\n";
        Character::display();
    }
};


class Player : public Character {
public:
    // Constructor
    Player(int h, int d) : Character(h, d) {}

    // Display function
    void display() {
        cout << "🧝 Player Stats:\n";
        Character::display();
    }
};

// Wizard class (derived from Player)
class Wizard : public Player {
private:
    int magicPower;
    string spell;

public:
    // Constructor
    Wizard(int h, int d, int mp, string sp)
        : Player(h, d) {
        magicPower = mp;
        spell = sp;
    }

    // Display function
    void display() {
        cout << "🧙‍♂️ Wizard Stats:\n";
        Player::display();  // Call Player → Character
        cout << "Magic Power: " << magicPower << endl;
        cout << "Spell: " << spell << endl;
    }
};

// Main function
int main() {
    Wizard w(100, 25, 80, "Fireball");

    cout << "✨ Summoning Wizard...\n\n";
    w.display();

    return 0;
}
