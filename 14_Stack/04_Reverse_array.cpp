#include<iostream>
#include<stack>
using namespace std;

void reverseString(char arr[], int size)
{
    stack<char>st;
    for(int i=0; i<size; i++)
    {
        st.push(arr[i]);
    }
    int i=0;
    while(!st.empty())
    {
        arr[i] = st.top();
        st.pop();
        i++;
    }
};

int main()
{
    char arr[] = {'h','e','l','l','o'};

    // reverse string
    reverseString(arr, 5);

    // print value
    for(int i=0; i<5; i++)
    {
        cout<<arr[i]<<" "; // o l l e h 
    }
}