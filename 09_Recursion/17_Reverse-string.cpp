#include<iostream>
using namespace std;

void printReverse(string str, int index)
{
    if(index==-1)
    return;

    cout<<str[index];
    printReverse(str, index-1);
}

void printRev(string &str, int start, int end)
{
    if(start>=end)
    return;

    char c = str[start];
    str[start] = str[end];
    str[end] = c;

    printRev(str, start+1, end-1);
}

int main()
{
    string str = "sonukumar";

    // printReverse(str, 9); // ramukunos
    printRev(str, 0, 8);
    cout<<str; // ramukunos
}