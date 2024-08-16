#include <bits/stdc++.h>
using namespace std;
void dfs(int r, int c, vector<vector<char>> &board, vector<int> &di, vector<int> &dj)
{
    int n = board.size();
    int m = board[0].size();
    board[r][c] = 'K';
    for (int i = 0; i < 4; i++)
    {
        int I = r + di[i];
        int J = c + dj[i];
        if (I >= 0 && I < n && J >= 0 && J < m && board[I][J] == 'O')
        {
            // board[I][J]='K';
            dfs(I, J, board, di, dj);
        }
    }
}
void solve(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, 1, 0, -1};
    for (int i = 0; i < m; i++)
    {
        if (board[0][i] == 'O')
            dfs(0, i, board, di, dj);
        if (board[n - 1][i] == 'O')
            dfs(n - 1, i, board, di, dj);
    }
    for (int i = 0; i < n; i++)
    {
        if (board[i][0] == 'O')
            dfs(i, 0, board, di, dj);
        if (board[i][m - 1] == 'O')
            dfs(i, m - 1, board, di, dj);
    }
    // return board;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'K')
                board[i][j] = 'O';
            else
                board[i][j] = 'X';
        }
    }
}

