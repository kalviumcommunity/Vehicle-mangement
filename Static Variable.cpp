#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Tire {
private:
    string brand;
    string size;

    // Static variable to track the number of Tire instances
    static int tireCount;

public:
    Tire(const string& brand, const string& size) : brand(brand), size(size) {
        ++tireCount; // Increment count whenever a new Tire object is created
    }

    ~Tire() {
        --tireCount; // Decrement count whenever a Tire object is destroyed
    }

    string getBrand() const {
        return brand;
    }

    string getSize() const {
        return size;
    }

    void displayInfo() const {
        cout << "Tire Brand: " << this->brand << ", Size: " << this->size << endl;
    }

    // Static method to get the number of Tire instances
    static int getTireCount() {
        return tireCount;
    }
};

// Initialize static variable
int Tire::tireCount = 0;

class Vehicle {
private:
    string make;
    string model;
    Tire* tire;

    // Static variable to track the number of Vehicle instances
    static int vehicleCount;

public:
    Vehicle(const string& make, const string& model, Tire* tire) : make(make), model(model), tire(tire) {
        ++vehicleCount; // Increment count whenever a new Vehicle object is created
    }

    ~Vehicle() {
        --vehicleCount;
        delete tire;   
    }

    string getMake() const {
        return make;
    }

    string getModel() const {
        return model;
    }

    void displayInfo() const {
        cout << "Vehicle Make: " << this->make << ", Model: " << this->model << endl;
        cout << "Tire:" << endl;
        this->tire->displayInfo();  
    }

    // Static method to get the number of Vehicle instances
    static int getVehicleCount() {
        return vehicleCount;
    }
};

// Initialize static variable
int Vehicle::vehicleCount = 0;

int main() {
    Tire* tire1 = new Tire("Goodyear", "225/50R17");
    Tire* tire2 = new Tire("Michelin", "225/50R17");
    Tire* tire3 = new Tire("Bridgestone", "225/50R17");
    Tire* tire4 = new Tire("Pirelli", "225/50R17");
    Tire* tire5 = new Tire("Continental", "225/50R17");

    vector<Vehicle*> vehicles = {
        new Vehicle("Toyota", "Camry", tire1),
        new Vehicle("Honda", "Accord", tire2),
        new Vehicle("Ford", "Mustang", tire3),
        new Vehicle("Chevrolet", "Malibu", tire4),
        new Vehicle("Nissan", "Altima", tire5)
    };

    for (const auto& car : vehicles) {
        car->displayInfo();
        cout << endl;
    }

    // Display the number of Tire and Vehicle instances
    cout << "Total Tire instances: " << Tire::getTireCount() << endl;
    cout << "Total Vehicle instances: " << Vehicle::getVehicleCount() << endl;

    for (auto& car : vehicles) {
        delete car;
    }

    // Display the number of Tire instances after deletion
    cout << "Total Tire instances after deletion: " << Tire::getTireCount() << endl;

    return 0;
}
