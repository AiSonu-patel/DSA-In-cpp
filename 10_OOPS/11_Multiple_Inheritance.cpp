#include<iostream>
using namespace std;

class Engineer
{
    public:
    string specilization;

    Engineer()
    {
        cout<<"Hello Engineer\n";
    }

    void work()
    {
        cout<<"I have specilization in "<<specilization<<endl;
    }
};

class Youtuber
{
    public:
    int subscribers;

    Youtuber()
    {
        cout<<"Hello youtuber\n";
    }

    void contentcreator()
    {
        cout<<"I have a subscriber base of "<<subscribers<<endl;
    }
};

class CodeTeacher: public Engineer, public Youtuber
{
    public:
    string name;

    CodeTeacher()
    {
        cout<<"Hello coder\n";
    }

    CodeTeacher(string name, string specilization, int subscribers)
    {
        this->name = name;
        this->specilization = specilization;
        this->subscribers = subscribers;
    }

    void showcase()
    {
        cout<<"My name is "<<name<<endl;
        work();
        contentcreator();
    }
};

int main()
{
    CodeTeacher A1;
}