#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n<2)
    {
        cout<<"Not Prime";
        return 0;
    }
    else
    {
        for(int i=2; i<n; i++)
        {
            if(n%i==0)
            {
                cout<<"Not Prime";
                return 0;
            }
        }
        cout<<"prime";

        return 0;
    }
    return 0;
}