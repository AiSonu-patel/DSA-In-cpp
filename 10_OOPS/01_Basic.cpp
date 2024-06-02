#include<iostream>
using namespace std;

class Student
{
    private:
    string name;
    int age;
    int roll_number;
    string grade;
    // Function Getter and Setter
    public:
    void setname(string n)
    {
        if(n.size()==0)
        {
            cout<<" invalid name! : "<<n<<endl;
            return;
        }
        cout<<"Your name has been successfully set"<<endl;
        name = n;
    }

    void setage(int a)
    {
        if(a<=0||a>100)
        {
            cout<<"invalid age! : "<<a<<endl;
            return;
        }
        cout<<"Your age has been successfully set"<<endl;
        age = a;
    }

    void setroll_number(int r)
    {
        cout<<"Your roll_number has been successfully set"<<endl;
        roll_number = r;
    }

    void setgrade(string g)
    {
        if(g=="A"||g=="B"||g=="C"||g=="A+"||g=="B+"||g=="C+"||g=="A++"||g=="B++"||g=="C++")
        {
            cout<<"Your grade has been successfully set"<<endl;
            grade = g;
            return;
        }
        cout<<"invalid grade! :"<<g<<endl;
    }

    // Getter function
    void getname()
    {
        cout<<"Name: "<<name<<endl;
    }
    void getage()
    {
        cout<<"Age: "<<age<<endl;
    }
    void getroll_number()
    {
        cout<<"Roll_number: "<<roll_number<<endl;
    }
    void getgrade(int pin)
    {
        if(pin==123)
        {
            cout<<"Grade: "<<grade<<endl;
            return;
        }

        cout<<"Not show grade please enter valid Pin :"<<endl;
    }
};

class empty
{

};

class techer
{
    public:
    string name;
    string phone_number;
    string department;
};

int main()
{
    Student s1;
    s1.setname("sonu");
    s1.setage(20);
    s1.setroll_number(154);
    s1.setgrade("A++");

    s1.getname(); // Name: sonu
    s1.getage(); // Age: 20
    s1.getroll_number(); // Roll_number: 154
    s1.getgrade(123); // Grade: A++

    empty obj;
    cout<<sizeof(obj)<<endl; // 1

    techer *t = new techer;
    (*t).name = "sonu";
    (*t).phone_number = "1234567895";
    (*t).department = "CSA";

    cout<<t->name<<endl; // sonu
    cout<<t->phone_number<<endl; // 1234567895
    cout<<t->department<<endl; // CSA


}