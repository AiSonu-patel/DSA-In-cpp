#include<iostream>
using namespace std;
// The capability of s class to derive property & characteristic from another class.

class Human
{
    public:
    string name;
    int age, weight;
};

class Student: private Human
{   
    int roll_number, fees;
    public:
    Student(string name, int age, int weight, int roll_number, int fees)
    {
        this->name = name;
        this->age = age;
        this->weight = weight;
        this->roll_number = roll_number;
        this->fees = fees;
    }

    void display()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Weight: "<<weight<<endl;
        cout<<"Roll number: "<<roll_number<<endl;
        cout<<"Fees: "<<fees<<endl;
    }
};

class Techear: private Human
{
    int salary, id;
    public:
    Techear(string name, int age, int weight, int salary, int id)
    {
        this->name = name;
        this->age = age;
        this->weight = weight;
        this->salary = salary;
        this->id = id;
    }

    void display()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Weight: "<<weight<<endl;
        cout<<"Salary: "<<salary<<endl;
        cout<<"Id No.: "<<id<<endl;
    }
};

int main()
{
    Student A1("sonu", 21, 40, 154, 2000);
    A1.display();
    Techear T1("sonu", 21, 50, 2000, 101);
    T1.display();
}