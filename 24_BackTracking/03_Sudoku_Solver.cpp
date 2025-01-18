#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check(int num, vector<vector<char>> &board, int i, int j)
{
    char c = '0' + num;
    // check at same row
    for (int col = 0; col < 9; col++)
    {
        if (board[i][col] == c)
            return 0;
    }
    // check at same col
    for (int row = 0; row < 9; row++)
    {
        if (board[row][j] == c)
            return 0;
    }
    // check at same box
    int row = i / 3 * 3, col = j / 3 * 3;
    for (int a = row; a < row + 3; a++)
        for (int b = col; b < col + 3; b++)
        {
            if (board[a][b] == c)
                return 0;
        }

    return 1;
};

bool find(int i, int j, vector<vector<char>> &board)
{
    // base condition
    if (i == 9)
        return 1;

    if (j == 9)
        return find(i + 1, 0, board);

    if (board[i][j] != '.')
        return find(i, j + 1, board);

    for (int num = 1; num < 10; num++)
    {
        if (check(num, board, i, j))
        {
            board[i][j] = '0' + num;
            if (find(i, j + 1, board))
                return 1;

            board[i][j] = '.';
        }
    }

    return 0;
};

void solveSudoku(vector<vector<char>> &board)
{
    find(0, 0, board);
};

int main()
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '.', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '.', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solveSudoku(board);

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    // ans:-
    // 5 3 4 6 7 8 9 1 2
    // 6 7 2 1 9 5 3 4 8
    // 1 9 8 3 4 2 5 6 7
    // 8 5 9 7 6 1 4 2 3
    // 4 2 6 8 5 3 7 9 1
    // 7 1 3 9 2 4 8 5 6
    // 9 6 1 5 3 7 2 8 4
    // 2 8 7 4 1 9 6 3 5
    // 3 4 5 2 8 6 1 7 9
}