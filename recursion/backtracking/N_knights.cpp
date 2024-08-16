#include <bits/stdc++.h>
using namespace std;
void display(vector<string> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        cout << board[i] << endl;
    }
    cout << "___________________________" << endl;
}

bool check(int x, int y, vector<string> &mp)
{
    if (mp[x][y] == 'X')
    {
        return false;
    }
    return true;
}

void mark(char x, vector<string> &mp, int row, int col)
{
    if (row + 2 < 8 && col + 1 < 8)
    {
        mp[row + 2][col + 1] = x;
    }
    if (row + 2 < 8 && col - 1 <= 0)
    {
        mp[row + 2][col - 1] = x;
    }
    if (row - 2 >= 0 && col + 1 < 8)
    {
        mp[row - 2][col + 1] = x;
    }
    if (row - 2 >= 0 && col - 1 >= 0)
    {
        mp[row - 2][col - 1] = x;
    }
    if (row + 1 < 8 && col + 2 < 8)
    {
        mp[row + 1][col + 2] = x;
    }
    if (row + 1 < 8 && col - 2 >= 0)
    {
        mp[row + 1][col - 2] = x;
    }
    if (row - 1 >= 0 && col + 2 < 8)
    {
        mp[row - 1][col + 2] = x;
    }
    if (row - 1 >= 0 && col - 2 >= 0)
    {
        mp[row - 1][col - 2] = x;
    }
}

void solve(int n, vector<string> &board, vector<string> &mp, int row, int col)
{
    if (n == 0)
    {
        display(board);
        return;
    }
    if (col == 9)
    {
        solve(n, board, mp, row + 1, 0);
    }
    if (check(row, col, mp))
    {
        board[row][col] = 'K';
        mp[row][col] = 'X';
        mark('X', mp, row, col);
        solve(n - 1, board, mp, row, col + 1);
        board[row][col] = '.';
        mp[row][col] = '.';
        mark('.', mp, row, col);
        solve(n, board, mp, row, col + 1);
    }

    solve(n, board, mp, row, col + 1);
}
void n_knights(int n)
{
    vector<string> ans(8, string(8, '.'));
    vector<string> mp(8, string(8, '.'));
    solve(n, ans, mp, 0, 0);
    return;
}

int main()
{
    n_knights(9);
}