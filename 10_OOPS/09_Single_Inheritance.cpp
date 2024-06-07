#include<iostream>
using namespace std;

class Human
{
    protected:
    string name;
    int age;

    public:
    Human(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void display()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }

    void work()
    {
        cout<<"I am working\n";
    }
};

class Student: public Human
{
    int roll_number, fees;

    public:
    Student(string name, int age, int roll_number, int fees): Human(name, age)
    {
        // this->name = name;
        // this->age = age;
        this->roll_number = roll_number;
        this->fees = fees;
    }

    void display()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Roll Number: "<<roll_number<<endl;
        cout<<"Fees: "<<fees<<endl;
    }
};

int main()
{
    Student A1("sonu", 21, 154, 99);
    A1.work();
    A1.display();
}