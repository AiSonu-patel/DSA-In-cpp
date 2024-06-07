#include<iostream>
using namespace std;

// student
// boy
// girl
// male
// femal

class Student
{
    public:
    void print()
    {
        cout<<"I am student\n";
    }
};

class Male
{
    public:
    void Maleprint()
    {
        cout<<"I am Male\n";
    }
};

class FeMale
{
    public:
    void FeMaleprint()
    {
        cout<<"I am FeMale\n";
    }
};

class Boy: public Student, public Male
{
    public:
    void Boyprint()
    {
        cout<<"I am Boy\n";
    }
};

class Girl: public Student, public FeMale
{
    public:
    void Girlprint()
    {
        cout<<"I am Girl\n";
    }
};



int main()
{
    Girl G1;
    G1.FeMaleprint(); // I am FeMale
    G1.Girlprint(); // I am Girl
    G1.print(); // I am student

    Boy B1;
    B1.Boyprint(); // I am Boy
    B1.Maleprint(); // I am Male
    B1.print(); // I am student
}