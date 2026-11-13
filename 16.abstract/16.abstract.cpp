#include <iostream>
#include <string>
using namespace std;

class Employer
{
protected:
    string name;
    int age;
    double salary;

public:
    Employer(string name, int age, double salary)
    {
        this->name = name;
        this->age = age;
        this->salary = salary;
    }

    virtual void Print() const = 0;

    virtual ~Employer() {}
};

class President : public Employer
{
private:
    string company;

public:
    President(string name, int age, double salary, string company)
        : Employer(name, age, salary)
    {
        this->company = company;
    }

    void Print() const override
    {
        cout << "\nPresident:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
        cout << "Company: " << company << endl;
    }
};

class Manager : public Employer
{
private:
    string department;

public:
    Manager(string name, int age, double salary, string department)
        : Employer(name, age, salary)
    {
        this->department = department;
    }

    void Print() const override
    {
        cout << "\nManager:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
        cout << "Department: " << department << endl;
    }
};

class Worker : public Employer
{
private:
    string position;

public:
    Worker(string name, int age, double salary, string position)
        : Employer(name, age, salary)
    {
        this->position = position;
    }

    void Print() const override
    {
        cout << "\nWorker:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
        cout << "Position: " << position << endl;
    }
};

int main()
{
    President p("Ivan", 50, 100000, "Microsoft");
    Manager m("Oleg", 35, 50000, "IT");
    Worker w("Andriy", 25, 25000, "Programmer");

    Employer* employees[] = { &p, &m, &w };

    for (int i = 0; i < 3; i++)
    {
        employees[i]->Print();
    }

    return 0;
}





//2
class Transport
{
protected:
    string name;
    double speed;
    double price;
    int maxPassengers;
    double maxCargo;

public:
    Transport(string name, double speed, double price,
        int maxPassengers, double maxCargo)
    {
        this->name = name;
        this->speed = speed;
        this->price = price;
        this->maxPassengers = maxPassengers;
        this->maxCargo = maxCargo;
    }

    virtual double GetTime(double distance) const
    {
        return distance / speed;
    }

    virtual double GetPrice(double distance) const
    {
        return distance * price;
    }

    virtual void Show(double distance, int passengers,
        double cargo) const
    {
        cout << "\nTransport: " << name << endl;

        if (distance < 0 || passengers < 0 || cargo < 0)
        {
            cout << "Invalid data!" << endl;
            return;
        }

        if (passengers > maxPassengers || cargo > maxCargo)
        {
            cout << "Transport capacity exceeded!" << endl;
            return;
        }

        cout << "Distance: " << distance << " km" << endl;
        cout << "Passengers: " << passengers << endl;
        cout << "Cargo: " << cargo << " kg" << endl;
        cout << "Time: " << GetTime(distance) << " hours" << endl;
        cout << "Cost: " << GetPrice(distance) << " UAH" << endl;
    }

    virtual ~Transport() {}
};

class Car : public Transport
{
public:
    Car() : Transport("Car", 60, 10, 4, 400)
    {
    }

    double GetTime(double distance) const override
    {
        return distance / speed;
    }

    double GetPrice(double distance) const override
    {
        return distance * price;
    }
};

class Bicycle : public Transport
{
public:
    Bicycle() : Transport("Bicycle", 15, 2, 1, 20)
    {
    }

    double GetTime(double distance) const override
    {
        return distance / speed;
    }

    double GetPrice(double distance) const override
    {
        return distance * price;
    }
};

class Cart : public Transport
{
public:
    Cart() : Transport("Cart", 10, 5, 2, 500)
    {
    }

    double GetTime(double distance) const override
    {
        return distance / speed;
    }

    double GetPrice(double distance) const override
    {
        return distance * price;
    }
};

int main()
{
    Car car;
    Bicycle bicycle;
    Cart cart;

    Transport* transports[] = { &car, &bicycle, &cart };

    double distance;
    int passengers;
    double cargo;

    cout << "Enter distance (km): ";
    cin >> distance;

    cout << "Enter passengers: ";
    cin >> passengers;

    cout << "Enter cargo weight (kg): ";
    cin >> cargo;

    for (int i = 0; i < 3; i++)
    {
        transports[i]->Show(distance, passengers, cargo);
    }

    return 0;
}
