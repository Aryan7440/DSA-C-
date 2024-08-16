#include <bits/stdc++.h>
using namespace std;

int count(vector<vector<char>> &board, int x, int y)
{
    int n = board.size();
    int m = board[x].size();
    int M_count = 0;
    vector<int> dx = {-1, 0, 1, 0, -1, -1, 1, 1};
    vector<int> dy = {0, 1, 0, -1, -1, 1, -1, 1};
    for (int i = 0; i < 8; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (X >= 0 && X < n && Y >= 0 && Y < m && board[X][Y] == 'M')
        {
            M_count++;
        }
    }
    return M_count;
}
void update(vector<vector<char>> &board, int x, int y)
{
    int n = board.size();
    int m = board[x].size();
    if (board[x][y] == 'M')
    {
        board[x][y] = 'X';
        return;
    }
    else if (board[x][y] == 'E')
    {
        int M_count = count(board, x, y);
        if (M_count > 0)
            board[x][y] = to_string(M_count)[0];
        else
        {
            board[x][y] = 'B';
            vector<int> dx = {-1, 0, 1, 0, -1, -1, 1, 1};
            vector<int> dy = {0, 1, 0, -1, -1, 1, -1, 1};
            for (int i = 0; i < 8; i++)
            {
                int X = x + dx[i];
                int Y = y + dy[i];
                if (X >= 0 && X < n && Y >= 0 && Y < m && board[X][Y] == 'E')
                {
                    update(board, X, Y);
                }
            }
        }
    }
    return;
}
vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
{

    update(board, click[0], click[1]);
    return board;
}
int main()
{
    vector<vector<char>> board = { {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
                                   {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'M'},
                                   {'E', 'E', 'M', 'E', 'E', 'E', 'E', 'E'},
                                   {'M', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
                                   {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
                                   {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
                                   {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
                                   {'E', 'E', 'M', 'M', 'E', 'E', 'E', 'E'} };
    vector<int>click={0,0};
    vector<vector<char>>ans=updateBoard(board,click);
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}