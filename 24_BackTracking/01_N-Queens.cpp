#include <bits/stdc++.h>
using namespace std;

// Time Complexity O(n!)
// Space Complexity O(n*n)

// bool check(int n, vector<string>&Board, int i, int j)
// {
//     int row = i, col = j;
//     while(row>-1&&col>-1)
//     {
//         if(Board[row][col]=='Q')
//         return 0;
//         col--, row--;
//     }
//     row = i, col = j;
//     while(row>-1 && col<n)
//     {
//         if(Board[row][col]=='Q')
//         return 0;
//         row--, col++;
//     }
//     return 1;
// };


void find(int row, int n, vector<vector<string>>&ans, vector<string>&Board, vector<bool>&column, vector<bool>&leftDig, vector<bool>&rightDig)
{
    // base case

    if(row==n)
    {
        ans.push_back(Board);
        return;
    }

    // LeftDig : n-1+col-row
    // rightDig: row+col

    for(int j=0; j<n; j++)
    {
        if(column[j]==0 &&leftDig[n-1+j-row]==0&&rightDig[row+j]==0)
        {
            column[j] = 1;
            Board[row][j] = 'Q';
            leftDig[n-1+j-row] = 1;
            rightDig[row+j] = 1;
            find(row+1, n, ans, Board, column, leftDig, rightDig);
            column[j] = 0;
            Board[row][j] = '.';
            leftDig[n-1+j-row] = 0;
            rightDig[row+j] = 0;
        }
    }
};

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>>ans;
    vector<string>Board(n);
    vector<bool>column(n, 0);
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
    Board[i].push_back('.');

    vector<bool>rightDig(2*n-1, 0);
    vector<bool>leftDig(2*n-1, 0);


    find(0, n, ans, Board, column, leftDig, rightDig);

    return ans;

}

int main()
{
    int n = 4;
    vector<vector<string>>ans = solveNQueens(n);
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[0].size(); j++)
        {
            cout<<ans[i][j]<<" "; // [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
        } 
        cout<<endl;
    }
}