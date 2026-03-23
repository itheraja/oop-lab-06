#include <iostream>
using namespace std;


class Vehicle {
protected:
    string make;
    string model;
    int year;

public:
    // Constructor
    Vehicle(string mk, string mdl, int yr) {
        make = mk;
        model = mdl;
        year = yr;
    }

    void displayVehicle() {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

// Derived class: Car
class Car : public Vehicle {
protected:
    int doors;
    float fuelEfficiency;

public:
    // Constructor
    Car(string mk, string mdl, int yr, int d, float fe)
        : Vehicle(mk, mdl, yr) {
        doors = d;
        fuelEfficiency = fe;
    }

    void displayCar() {
        displayVehicle();
        cout << "Doors: " << doors << endl;
        cout << "Fuel Efficiency: " << fuelEfficiency << " km/l" << endl;
    }
};

// Derived class: ElectricCar
class ElectricCar : public Car {
private:
    int batteryLife;

public:
    // Constructor
    ElectricCar(string mk, string mdl, int yr, int d, float fe, int bl)
        : Car(mk, mdl, yr, d, fe) {
        batteryLife = bl;
    }

    void display() {
        cout << "⚡ Electric Car Details:\n";
        displayCar();
        cout << "Battery Life: " << batteryLife << " km per charge" << endl;
    }
};

// Main function
int main() {
    ElectricCar ec("Tesla", "Model 3", 2023, 4, 0.0, 500);

    cout << "🚗 Creating Electric Car...\n\n";
    ec.display();

    return 0;
}
