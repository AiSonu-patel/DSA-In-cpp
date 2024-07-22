#include<iostream>
using namespace std;

// Implement it with using linked list
class Node
{
    public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Stack
{
    Node *top;
    int size;
    public:
    bool flag;
    Stack()
    {
        top = NULL;
        size = 0;
        flag = 1;
    }

    // push
    void push(int value)
    {
        Node *temp = new Node(value);
        if(temp==NULL)
        {
            cout<<"Stack overflow\n";
            return;
        }
        temp->next = top;
        top = temp;
        size++;
        cout<<"Pushed "<<value<<" into the stack\n";
        flag = 0;
    }
    // pop
    void pop()
    {
        if(top==NULL)
        {
            cout<<"Stack underflow\n";
            return;
        }
        else
        {
            Node *temp = top;
            cout<<"Poped "<<top->data<<" from the stack\n";
            top = top->next;
            delete temp;
            size--;
            if(top==NULL)
            flag=1;
        }
    }
    // peek
    int peek()
    {
        if(top==NULL)
        {
            cout<<"Stack is Empty\n";
            return -1;
        }
        else
        {
            return top->data;
        }
    }
    // isEmpty
    bool isEmpty()
    {
        return top==NULL;
    }
    // isSize
    int isSize()
    {
        return size;
    }
};

int main()
{
    Stack S;
    S.push(-1);
    int value = S.peek();
    if(S.flag==0)
    cout<<value<<endl;
    
}