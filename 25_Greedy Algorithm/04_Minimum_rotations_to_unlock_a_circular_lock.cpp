#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*  Given a lock made up of N different circular rings. Each ring has 0-9 digit printed on it.     There is only one particular code which can open the lock. You can rotate each ring any number of times in either direction. Given the random sequence R and the desired sequence D, find the minimum number of rotations required to open the lock.
*/

// Expected Time Complexity: O(logR)
// Expected Auxiliary Space: O(1)

int rotationCount(long long R, long long D)
{
    int ans = 0;
    int first, second;
    while(R)
    {
        first = R%10;
        second = D%10;
        R/=10;
        D/=10;
        ans += min(abs(first-second), 10-abs(first-second));
    }
    return ans;
}

int main()
{
    int R = 222;
    int D = 333;
    cout<<rotationCount(R, D); // 3
}