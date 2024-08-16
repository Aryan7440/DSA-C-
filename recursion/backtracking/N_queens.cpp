#include <bits/stdc++.h>
using namespace std;
// striver method
bool check(vector<bool> leftrow, vector<bool> upper_diagonal, vector<bool> lower_diagonal, int x, int y, int n)
{
    if (leftrow[x] == false && upper_diagonal[n - 1 + (x - y)] == false && lower_diagonal[x + y] == false)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void solve(int n, int col, vector<vector<string>> &ans, vector<string> &board, vector<bool> &leftrow, vector<bool> &upper_diagonal, vector<bool> &lower_diagonal)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (check(leftrow, upper_diagonal, lower_diagonal, row, col, n))
        {
            board[row][col] = 'Q';// put queen
            leftrow[row] = true;
            upper_diagonal[n - 1 + (row - col)] = true;
            lower_diagonal[row + col] = true;
            solve(n, col + 1, ans, board, leftrow, upper_diagonal, lower_diagonal);
            board[row][col] = '.';// backtrack
            leftrow[row] = false;
            upper_diagonal[n - 1 + (row - col)] = false;
            lower_diagonal[row + col] = false;
        }
    }
}



// saif sir method
bool check(int row, int col, int n, vector<string> &board)
{
    int dcol = col;
    int drow = row;
    while (dcol >=0)// checks columns
    {
        if (board[row][dcol--] == 'Q')
        {
            return false;
        }
    }

    dcol = col;
    drow=row;
    while (dcol >=0 && drow >= 0)//  checks lower diagonal
    {
        if (board[drow--][dcol--] == 'Q')
        {
            return false;
        }
    }

    drow = row;
    dcol = col;
    while (dcol >=0 && drow < n)  // checks upper diagonal
    {
        if (board[drow++][dcol--] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void solve2(int n, int col, vector<vector<string>> &ans, vector<string> &board)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (check(row, col, n, board))
        {
            board[row][col] = 'Q';// put queen
            solve2(n, col + 1, ans, board);
            board[row][col] = '.';// backtrack
        }
    }
}



vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    vector<bool> leftrow(n, false);
    vector<bool> upper_diagonal(2 * n - 1, false);
    vector<bool> lower_diagonal(2 * n - 1, false);
    // solve(n, 0, ans, board, leftrow, upper_diagonal, lower_diagonal);// striver method
    solve2(n, 0, ans, board);                                           // saif sir method
    return ans;  
}

int main()
{
    vector<vector<string>> ans = solveNQueens(4);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << endl;
        }
        cout << "-----------------------------------------------------" << endl;
    }
}