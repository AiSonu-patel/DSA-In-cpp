#include<iostream>
using namespace std;

class Human
{
    public:
    string name;

    void display()
    {
        cout<<"My name is "<<name<<endl;
    }
};

class Engineer : public virtual Human
{
    public:
    string specilization;


    void work()
    {
        cout<<"I have specilization in "<<specilization<<endl;
    }
};

class Youtuber: public virtual Human
{
    public:
    int subscribers;


    void contentcreator()
    {
        cout<<"I have a subscriber base of "<<subscribers<<endl;
    }
};

class CodeTeacher: public Youtuber, public Engineer
{
    public:
    int salary;

    CodeTeacher()
    {

    };

    CodeTeacher(string name, string specilization, int subscribers, int salary)
    {
        this->name = name;
        this->specilization = specilization;
        this->subscribers = subscribers;
        this->salary = salary;
    }

};

int main()
{
    CodeTeacher A1("sonu", "CSA", 100, 99);
    A1.display();
}