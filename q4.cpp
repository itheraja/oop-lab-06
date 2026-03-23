#include <iostream>
using namespace std;


class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Student class (virtual inheritance)
class Student : virtual public Person {
protected:
    int studentID;
    string gradeLevel;

public:
    Student(string n, int a, int id, string grade)
        : Person(n, a) {
        studentID = id;
        gradeLevel = grade;
    }

    void displayStudent() {
        cout << "Student ID: " << studentID << endl;
        cout << "Grade Level: " << gradeLevel << endl;
    }
};

// Teacher class (virtual inheritance)
class Teacher : virtual public Person {
protected:
    string subject;
    int roomNumber;

public:
    Teacher(string n, int a, string sub, int room)
        : Person(n, a) {
        subject = sub;
        roomNumber = room;
    }

    void displayTeacher() {
        cout << "Subject: " << subject << endl;
        cout << "Room Number: " << roomNumber << endl;
    }
};

// GraduateStudent class
class GraduateStudent : public Student, public Teacher {
public:
    GraduateStudent(string n, int a, int id, string grade,
                    string sub, int room)
        : Person(n, a),   // must initialize virtual base
          Student(n, a, id, grade),
          Teacher(n, a, sub, room) {}

    void display() {
        cout << "🎓 Graduate Student Details:\n";
        displayPerson();
        displayStudent();
        displayTeacher();
    }
};

// Main function
int main() {
    GraduateStudent gs("Ali", 24, 12345, "Masters", "Computer Science", 101);

    cout << "📚 Summoning Graduate Student...\n\n";
    gs.display();

    return 0;
}
