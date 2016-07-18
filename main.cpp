#include <bits/stdc++.h>
#include <string>
using namespace std;

class Car
{
public:
    Car() {
        consume = 0;
        leak = 0;
        fuel = 0;
        distance = 0;
        totalDistance = 0;
        majorGasStationCost = 0;
    }
    void walk() {
        fuel += (distance*(consume+leak));
    }

    double fuelNeeded() {
        if(fuel > majorGasStationCost) return fuel;
        return majorGasStationCost;
    }

    double getConsume() const;
    void setConsume(double value);

    double getLeak() const;
    void setLeak(double value);

    double getFuel() const;
    void setFuel(double value);

    double getDistance() const;
    void setDistance(double value);

    double getTotalDistance() const;
    void setTotalDistance(double value);

    double getMajorGasStationCost() const;
    void setMajorGasStationCost(double value);

private:
    double consume;
    double leak;
    double fuel;
    double distance;
    double totalDistance;
    double majorGasStationCost;
};

bool itEquals(string a, string b) {
    if(a.compare(b) != 0) return false;
    return true;
}

bool contains(string str, string other) {
    if(str.find(other) == string::npos) return false;
    return true;
}

vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str); // Turn the string into a stream.
    string tok;

    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }

    return internal;
}

bool howMuchHasConsumed(string str, Car *car) {

    vector<string> aux = split(str,' ');
    car->setDistance(stod(aux.at(0)) - car->getTotalDistance());
    car->setTotalDistance(stod(aux.at(0)));
    car->walk();

    if(contains(str,"Fuel consumption")) {
        car->setConsume(stod(aux.at(3))/100);
    } else if(contains(str,"Goal")) {
        return false;
    } else if(contains(str,"Leak")) {
        car->setLeak(car->getLeak()+1);
    } else if(contains(str,"Gas station")) {
        car->setMajorGasStationCost(car->getFuel());
        car->setFuel(0);
    } else if(contains(str,"Mechanic")) {
        car->setLeak(0);
    }
    return true;
}

vector<Car *> getEntry() {
    vector<string> lines;
    string aux = "";
    while(!itEquals(aux,"0 Fuel consumption 0")) {
        getline(cin, aux);
        lines.push_back(aux);
    }
    lines.pop_back();
    bool check = false;
    vector<Car *> cars;
    for (string line : lines) {
        Car *car;
        if(!check) {
            car = new Car();
            check = true;
            cars.push_back(car);
        }
        check = howMuchHasConsumed(line,car);
    }
    return cars;
}

int main(int argc, char *argv[])
{
    vector<Car *> cars;
    cars = getEntry();
    for(Car *c : cars) {
        printf("%.3f\n", c->fuelNeeded());
    }
    return 0;
}

double Car::getConsume() const
{
    return consume;
}

void Car::setConsume(double value)
{
    consume = value;
}

double Car::getLeak() const
{
    return leak;
}

void Car::setLeak(double value)
{
    leak = value;
}

double Car::getFuel() const
{
    return fuel;
}

void Car::setFuel(double value)
{
    fuel = value;
}

double Car::getDistance() const
{
    return distance;
}

void Car::setDistance(double value)
{
    distance = value;
}

double Car::getTotalDistance() const
{
    return totalDistance;
}

void Car::setTotalDistance(double value)
{
    totalDistance = value;
}

double Car::getMajorGasStationCost() const
{
return majorGasStationCost;
}

void Car::setMajorGasStationCost(double value)
{
    if(value > majorGasStationCost)  majorGasStationCost = value;
}

