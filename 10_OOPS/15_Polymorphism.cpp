#include<iostream>
using namespace std;
// compile time
// Function overloading work
class Area
{
    public:
    int calculateArea(int r) // circle
    {
        return 3.14*r*r;
    }

    int calculateArea(int l, int b) // Rectangle 
    {
        return l*b;
    }
};

// Operator overloading

class Complex
{
    int real, img;
    public:
    Complex()
    {

    };

    Complex(int real, int img)
    {
        this->real = real;
        this->img = img;
    }

    void display()
    {
        cout<<real<<" + i"<<img<<endl;
    }

    Complex operator + (Complex &C)
    {
        Complex ans;
        ans.real = real+C.real;
        ans.img = img+C.img;
        return ans;
    }
};

// Run time
// Virtual function
class Animal
{
    public:

    virtual void speak()=0; // Abstract class
};

class Dog : public Animal
{
    public:

    void speak()
    {
        cout<<"Bark\n";
    }
};

int main()
{

    Dog d1;
    d1.speak(); // Bark

    Animal *p;
    p = new Dog();
    p->speak(); // Bark

    // Complex C1(3,4);
    // Complex C2(4,6);
    
    // Complex C3 = C1+C2;
    // C3.display(); // 7 + i10

    // Area A1, A2;
    // cout<<A1.calculateArea(4)<<endl;
    // cout<<A2.calculateArea(3,4)<<endl;
};