#include<iostream>
using namespace std;

// Implement it with using array
class Stack
{
    int *arr;
    int size;
    int top;

    public:
    // Constructor
    bool flag;
    Stack(int s)
    {
        size = s;
        arr = new int[s];
        top = -1;
        flag=1;
    }

    //push
    void push(int value)
    {
        if(top==size-1)
        {
            cout<<"Stack overflow\n";
            return;
        }
        else
        {
            top++;
            arr[top]=value;
            cout<<"Push "<<value<<" into stack\n";
            flag=0;
        }
    }
    //pop
    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack underflow\n";
        }
        else
        {
            cout<<"Pop "<<arr[top]<<" from the stack\n";
            top--;
            if(top==-1)
            flag=1;
        }
    }
    //peek
    int peek()
    {
        if(top==-1)
        {
            cout<<"Stack is Empty\n";
            return -1;
        }
        else
        {
            return arr[top];
        }
    }
    //isSize
    int isSize()
    {
        return top+1;
    }
    //isEmpty
    bool isEmpty()
    {
        return top==-1;
    }
};

int main()
{
    Stack S(5);
    S.push(-1);
    int value = S.peek();
    if(S.flag==0)
    cout<<value<<endl;

}
