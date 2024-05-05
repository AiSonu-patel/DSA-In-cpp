#include<iostream>
using namespace std;

int main()
{
    // Array create karna hai, jo store karega address
    int n,m;
    cin>>n>>m; // n -> row, m -> col
    int **ptr = new int *[n];
    // created 2D Array
    for(int i=0; i<n; i++)
    {
        ptr[i] = new int [m];
    }
    // enter the values
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
    cin>>ptr[i][j];

    // print the values
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        cout<<ptr[i][j]<<" ";
        cout<<endl;
    }

    // Release the memory, heap
    for(int i=0; i<n; i++)
    delete[] ptr[i];

    delete[] ptr;
}