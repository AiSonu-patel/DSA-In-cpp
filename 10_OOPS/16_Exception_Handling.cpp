#include<iostream>
using namespace std;

class Customer
{
    string name;
    int balance, account_number;
    public:
    Customer(string name, int balance, int account_number)
    {
        this->name = name;
        this->balance = balance;
        this->account_number = account_number;
    }

    // Deposit
    void deposit(int amount)
    {
        if(amount<=0)
        throw runtime_error("amount should be greater then 0!");

        balance+=amount;
        cout<<amount<<" rs. is credited successfully"<<endl;
    }
    // Withdrow
    void withdrow(int amount)
    {
        if(amount>0 && amount<=balance)
        {
            balance-=amount;
            cout<<amount<<" rs. is debites successfully"<<endl;
        }
        else if(amount<0)
        {
            // cout<<"amount should be greater then 0!\n";
            throw runtime_error("amount should be greater then 0!");

        }
        else
        {
            // cout<<"Your balance is low!\n";
            throw runtime_error("Your balance is low!");
        }
    }

    void total_Amount()
    {
        cout<<"Total amount of Rs."<<balance<<endl;
    }
};

int main()
{
    Customer C1("sonu", 5000, 4460);
    try{
    C1.deposit(100);
    C1.withdrow(6000);
    C1.total_Amount();
    }
    catch(const runtime_error &e)
    {
        cout<<"Exception Occured: "<<e.what()<<endl;
    }
}