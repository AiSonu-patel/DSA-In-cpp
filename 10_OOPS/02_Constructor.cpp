#include<iostream>
using namespace std;

class Customer
{
    string name;
    int account_number;
    int balance;
    public:
    // Default Constructor
    Customer()
    {
        cout<<"Constructor is called!"<<endl;
    }

    // Parameterized Constructor
   Customer(string name, int account_number, int balance)
    {
        this->name=name;
        this->account_number=account_number;
        this->balance=balance;
    }


    // Constructor Overloading
    Customer(string a, int b)
    {
        name=a;
        account_number=b;
        balance=100;
    }

/* 
    // Inline Constructor
    inline Customer(string a, int b, int c): name(a),account_number(b),balance(c)
    {

    }
*/
    // Copy Constructor
    Customer(Customer &B)
    {
        name = B.name;
        account_number = B.account_number;
        balance = B.balance;
    }

    void display()
    {
        cout<<name<<" "<<account_number<<" "<<balance<<" "<<endl;
    }
    
};

int main()
{
    Customer A1;
    Customer A2("sonu",5,100);
    Customer A3("sonu",10);
    // A1.display(); randome values
    A2.display(); // sonu 5 100
    A3.display(); // sonu 10 100
    Customer A4(A3);
    A4.display(); // sonu 10 100
    Customer A5;
    A5 = A3;
    A5.display(); // sonu 10 100
}