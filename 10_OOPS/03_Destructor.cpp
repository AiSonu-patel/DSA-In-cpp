#include<iostream>
using namespace std;

class Customer
{
    string name;
    int *data;
    public:
    // Default Constructor
    Customer()
    {
        name="sonu";
        data = new int;
        *data = 100;
        cout<<"Constructor is called\n";
    }
    // Destructor
    ~Customer()
    {
        delete data;
        cout<<"Destructor is called\n";
    }

};

int main()
{
    Customer A1;

}