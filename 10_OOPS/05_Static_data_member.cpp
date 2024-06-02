#include<iostream>
using namespace std;

class Customer
{
    string name;
    int account_number, balance;
    static int total_customer;
    static int total_balance;

    public:
    Customer(string name, int account_number, int balance)
    {
        this->name = name;
        this->account_number = account_number;
        this->balance = balance;
        total_customer++;
        total_balance+=balance;
    }

    static void acceStatic()
    {
        cout<<"Total Customers: "<<total_customer<<endl;
        cout<<"Total Balances: "<<total_balance<<endl;
    }

    void deposit(int amount)
    {
        if(amount>0)
        {
            balance+=amount;
            total_balance+=amount;
        }
    }

    void withdrow(int amount)
    {
        if(amount<=balance&&amount>0)
        {
            balance-=amount;
            total_balance-=amount;
        }
    }

    void display()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Account No.: "<<account_number<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
    void totalCustomer()
    {
        cout<<total_customer<<endl;
    }
};

int Customer::total_customer=0;
int Customer::total_balance=0;

int main()
{
    Customer A1("sonu", 1, 1000);
    Customer A2("satyam", 2, 1800);
    A1.display();
    A2.display();
    Customer A3("Mohit",3,2000);
    A3.display();
    A3.totalCustomer(); // 3
    A1.deposit(800);
    A2.withdrow(500);
    A1.display();
    A1.deposit(200);
    A1.display();

    Customer::acceStatic(); // 3

}