#include<iostream>
using namespace std;

class Human
{
    protected:
    string name;
    int age;

    public:

    Human()
    {

    };

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
        cout<<"I am working \n";
    }
};

class Student: public Human
{
    int roll_number, fees;
    public:
    Student(string name, int age, int roll_number, int fees) : Human(name, age)
    {
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

class Teacher: public Human
{
    int salary;
    public:

    Teacher(string name, int age, int salary)
    {
        this->name = name;
        this->age = age;
        this->salary = salary;
    }

    void display()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Salary: "<<salary<<endl;
    }
};

int main()
{
    Human A1("sonu", 21);
    // A1.display();
    // A1.work();
    Teacher A2("satyam", 16, 1000);
    A2.display();
}