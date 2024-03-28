#include<iostream>
using namespace std;

/*
Enter the Number: 2
2 X 1 = 2
2 X 2 = 4
2 X 3 = 6
2 X 4 = 8
2 X 5 = 10
2 X 6 = 12
2 X 7 = 14
2 X 8 = 16
2 X 9 = 18
2 X 10 = 20
*/

int main()
{
    int n;
    cout<<"Enter the Number: ";
    cin>>n;
    
    int i = 1;
    while(i<=10)
    {
        cout<<n<<" X "<<i<<" = "<<n*i<<endl;
        i++;
    }

}