#include <iostream>
using namespace std;

// Base class
class Device {
protected:
    string brand;
    string model;

public:
    Device(string b, string m) {
        brand = b;
        model = m;
    }

    void displayDevice() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
    }
};

// Smartphone class (virtual inheritance)
class Smartphone : virtual public Device {
protected:
    int simSlots;

public:
    Smartphone(string b, string m, int sim)
        : Device(b, m) {
        simSlots = sim;
    }

    void displaySmartphone() {
        cout << "SIM Slots: " << simSlots << endl;
    }
};

// Tablet class (virtual inheritance)
class Tablet : virtual public Device {
protected:
    bool stylusSupport;

public:
    Tablet(string b, string m, bool stylus)
        : Device(b, m) {
        stylusSupport = stylus;
    }

    void displayTablet() {
        cout << "Stylus Support: " << (stylusSupport ? "Yes" : "No") << endl;
    }
};

// HybridDevice class
class HybridDevice : public Smartphone, public Tablet {
public:
    HybridDevice(string b, string m, int sim, bool stylus)
        : Device(b, m),   // MUST initialize virtual base
          Smartphone(b, m, sim),
          Tablet(b, m, stylus) {}

    void display() {
        cout << "📱💻 Hybrid Device Details:\n";
        displayDevice();     
        displaySmartphone();  
        displayTablet();      
    }
};

// Main function
int main() {
    HybridDevice hd("Samsung", "Galaxy Hybrid", 2, true);

    cout << "🚀 Launching Hybrid Device...\n\n";
    hd.display();

    return 0;
}
