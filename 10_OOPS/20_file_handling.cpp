#include<iostream>
#include<fstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>arr(5);
    cout<<"Enter the input: ";
    for(int i=0; i<5; i++)
    {
        cin>>arr[i];
    }

    // open file karo
    ofstream fout; // it is used only write 
    fout.open("zero.txt");
    fout<<"Original data:\n";
    for(int i=0; i<5; i++)
    {
        fout<<arr[i]<<" ";
    }

    fout<<"\nSorted data\n";
    sort(arr.begin(), arr.end());
    for(int i=0; i<5; i++)
    {
        fout<<arr[i]<<" ";
    }

    fout.close();

}