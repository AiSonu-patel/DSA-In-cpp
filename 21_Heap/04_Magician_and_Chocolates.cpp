#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int nChoc(int A,  vector<int> &B)
{
    priority_queue<int>p;
    for(int i=0; i<B.size(); i++)
    p.push(B[i]);

    long long MaxCho = 0;
    while(A&&(!p.empty()))
    {
        MaxCho += p.top();

        if(p.top()/2)
        p.push(p.top()/2);

        p.pop();
        A--;
    }
    return MaxCho%1000000007;
}

int main()
{
    vector<int>B = {2, 4, 6, 8, 10};
    int A = 5;

    cout<<nChoc(A, B); // 33
}