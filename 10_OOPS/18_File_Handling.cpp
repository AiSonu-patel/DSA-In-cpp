#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    // file ko open karna
    ofstream fout; // fout is object
    fout.open("zoom.txt"); // create kar dega aur fr open kar dega
    // write kar sakta hu
    fout<<"Welcome to India";

    fout.close(); // Resource release kar paauon
}