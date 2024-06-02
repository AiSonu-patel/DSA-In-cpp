#include<iostream>
using namespace std;
// Displaying only essential information & hiding the details.

class Customer
{
    string name;
    int age;
    int account_number;
    int balance;
    public:
    Customer(string name, int age, int account_number, int balance)
    {
        this->name=name;
        this->age=age;
        this->account_number=account_number;
        this->balance=balance;
    }

    void updateage(int age)
    {
        if(age>0 && age<=100)
        {
            this->age=age;
        }
        else
        {
            cout<<"Invalid Age"<<endl;
        }
    }
    // hide the code
    void deposit(int amount)
    {
        if(amount>0)
        {
            balance+=amount;
        }
        else
        {
            cout<<"Invalid amount: "<<amount<<endl;
        }
    }

    void withdrawal(int amount)
    {
        if(amount>0 && amount<=balance)
        {
            balance-=amount;
        }
        else
        {
            cout<<"Invalid amount: "<<amount<<endl;
        }
    }

    void display()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Account Number: "<<account_number<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
};

int main()
{
    Customer A1("SONU KUMAR", 21, 4460, 2000);
    Customer A2("SATYAM KUMAR", 17, 1768, 5000);
    A2.display();
    A2.deposit(100); // it see only user
    A2.display();
}