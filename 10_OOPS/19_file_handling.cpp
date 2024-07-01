#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    // only read file
    ifstream read;
    // file ko open karo
    read.open("zoom.txt");
    // fr read karo
    char c;
    c = read.get();
    while(!read.eof())
    {
        cout<<c;
        c = read.get();
    }

    read.close();
}