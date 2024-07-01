#include<iostream>
#include<fstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>arr(9);
    // read file
    ifstream fin;
    fin.open("z2.txt");
    int n;
    fin>>n;
    while(!fin.eof())
    {
        for(int i=0; i<9; i++)
        {
            arr[i] = n;
            fin>>n;
        }
        
    }
    
    fin.close();

    ofstream fout;
    fout.open("z2.txt");
    // fout<<"\nSorted data:\n";
    sort(arr.begin(), arr.end());
    for(int i=0; i<arr.size(); i++)
    {
        fout<<arr[i]<<" ";
    }

    fout.close();




}