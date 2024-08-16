#include <bits/stdc++.h>
using namespace std;

// bool check(vector<vector<int>> &board,int val, int i, int j)
// {
//     int row = i - i%3, column = j - j%3;
//     for(int x=0; x<9; x++) if(board[x][j] == val) return false;
//     for(int y=0; y<9; y++) if(board[i][y] == val) return false;
//     for(int x=0; x<3; x++)
//     for(int y=0; y<3; y++)
//         if(board[row+x][column+y] == val) return false;
//     return true;
// }

bool check(vector<vector<int>> &board, int num, int row, int col)
{
    for (int i = 0; i < board[row].size(); i++)
    {
        if (board[row][i] == num)
            return false;
    }
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i][col] == num)
            return false;
    }
    int x = row - (row % 3);
    int y = col - (col % 3);
    for (int i = x; i < x + 3; i++)
    {
        for (int j = y; j < y + 3; j++)
        {
            if (board[i][j] == num)
                return false;
        }
    }
    return true;

    // for (int i = 0; i < 9; i++)
    // {
    //     if (board[i][col] == num)
    //         return false;
    //     if (board[row][i] == num)
    //         return false;
    //     if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
    //         return false;
    //     // return true;
    // }
    // return true;
}

bool sudoku_solver(vector<vector<int>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 0)
            {
                for (int n = 1; n <= 9; n++)
                {
                    if (check(board, n, i, j))
                    {
                        board[i][j] = n;
                        if (sudoku_solver(board))
                        {
                            return true;
                        }
                        else
                        {
                            board[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }

    return true;
}
void display(vector<vector<int>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-----------------------------------------" << endl;
}


class Solution {
public:
    bool check(vector<vector<char>> board,int row,int col,char num)
    {
        // for(int i=0;i<board[row].size();i++)
        // {
        //     if(board[row][i]==num)
        //     {
        //         return false;
        //     }
        // }
        // for(int i=0;i<board.size();i++)
        // {
        //     if(board[i][col]==num)
        //     {
        //         return false;
        //     }
        // }
        // int x=row-row%3;
        // int y=col-col%3;
        // for(int i=x;i<x+3;i++)
        // {
        //     for(int j=y;j<y+3;j++)
        //     {
        //         if(board[i][j]==num)
        //         {
        //             return false;
        //         }
        //     }
        // }
        // return true;
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == num)
                return false;
            if (board[row][i] == num)
                return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
                return false;
            // return true;
        }
        return true;
    }
    // bool solve(vector<vector<char>> &board)
    // {
    //     for(int i=0;i<board.size();i++)
    //     {
    //         for(int j=0;j<board[i].size();j++)
    //         {
    //             if(board[i][j]=='.')
    //             {
    //                 for(char n='1';n<='9';n++)
    //                 {
    //                     if(check(board,i,j,n))
    //                     {
    //                         board[i][j]=n;
    //                         if(solve(board))
    //                         {
    //                             return true;
    //                         }
    //                         else
    //                         {
    //                             board[i][j]='.';
    //                         }
    //                     }
    //                 }
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }
    
    bool solve2(vector<vector<char>>&board,int x,int y)
    {
        if(x==9)return true;
        if(y==9)
        {
            // y=0;
            return solve2(board,x+1,0);
        }
        if(board[x][y]!='.')
        {
            return solve2(board,x,y+1);
        }
        for(char i='1';i<='9';i++)
        {
             if(check(board,x,y,i)) 
             {
                 board[x][y]=i;
                 if(solve2(board,x,y+1))
                 {
                     return true;
                 }
                 board[x][y]='.';
             }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
       // solve(board);
        solve2(board,0,0);
    }
};
int main()
{
    vector<vector<int>> board = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                                 {5, 2, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 8, 7, 0, 0, 0, 0, 3, 1},
                                 {0, 0, 3, 0, 1, 0, 0, 8, 0},
                                 {9, 0, 0, 8, 6, 3, 0, 0, 5},
                                 {0, 5, 0, 0, 9, 0, 6, 0, 0},
                                 {1, 3, 0, 0, 0, 0, 2, 5, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 7, 4},
                                 {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    display(board);
    sudoku_solver(board);
    display(board);
}