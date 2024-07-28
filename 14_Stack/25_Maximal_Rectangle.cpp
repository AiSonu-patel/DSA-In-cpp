#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int rectangle(vector<char>hight)
{
    int ans=0;
    int index;
    int n = hight.size();
    stack<int>st;
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && hight[st.top()]>hight[i])
        {
            index = st.top();
            st.pop();
            if(!st.empty())
            ans = max(ans, hight[index]*(i-st.top()-1));
            else
            ans = max(ans, hight[index]*i);
        }
        st.push(i);
    }
    while(!st.empty())
    {
        index = st.top();
        st.pop();
        if(!st.empty())
        ans = max(ans, hight[index]*(n-st.top()-1));
        else
        ans = max(ans, hight[index]*n);
    }
    return ans;
};

int maxiRectangle(vector<vector<char>> arr)
{
    int row = arr.size();
    int col = arr[0].size();
    int ans=0;
    vector<char>hight(col);
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(arr[i][j]=='0')
            {
                hight[j] = 0;
            }
            else
            {
                hight[j] += 1;
            }
        }
        ans = max(ans, rectangle(hight));
    }

    return ans;
};

int main()
{
    vector<vector<char>>arr = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    
    cout<<maxiRectangle(arr)<<endl; // 6

    // print values
    // for(int i=0; i<arr.size(); i++)
    // {
    //     for(int j=0; j<arr[0].size(); j++)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    
}