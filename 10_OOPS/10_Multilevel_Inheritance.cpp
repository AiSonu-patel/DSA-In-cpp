#include<iostream>
using namespace std;

class Person
{
    protected:
    string name;

    public:
    void indroduce()
    {
        cout<<"Hello my name is: "<<name<<endl;
    }
};

class Employee: public Person
{
    protected:
    int salary;

    public:

    void monthly_salary()
    {
        cout<<"My monthly salary is: "<<salary<<endl;
    }
};

class Manager: public Employee
{
    protected:
    string department;

    public:
    Manager(string name, int salary, string department)
    {
        this->name = name;
        this->salary = salary;
        this->department = department;
    }

    void work()
    {
        cout<<"I am leading the department: "<<department<<endl;
    }
};

int main()
{
    Manager A("sonu", 200, "CSA");
    A.indroduce(); // Hello my name is: sonu
    A.work(); // I am leading the department: CSA
    A.monthly_salary(); // My monthly salary is: 200
}