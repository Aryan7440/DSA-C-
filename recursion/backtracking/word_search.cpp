#include <bits/stdc++.h>
using namespace std;

bool UTIL(vector<vector<char>> &board, string word, int x, int y, int i, vector<int> &di, vector<int> &dj)
{
    if (i == word.size())
        return true;
    for (int j = 0; j < 4; j++)
    {
        int I = x + di[j];
        int J = y + dj[j];
        if (I<board.size() && I>=0 && J<board[0].size() && J>=0 && board[I][J] == word[i])
        {
            board[I][J] = '0';
            if (UTIL(board, word, I, J, i + 1, di, dj))
                return true;
            board[I][J] = word[i];
        }
    }
    return false;
}
bool exist(vector<vector<char>> &board, string word)
{
    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, 1, 0, -1};
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == word[0])
            {
                board[i][j]='0';
                if (UTIL(board, word, i, j, 1, di, dj))
                    return true;
                board[i][j]=word[0];
            }
        }
    }
    return false;
}
int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    // vector<string> board = {"ABCE", "SFCS", "ADEE"};
    string word = "ABCCED";
    cout << exist(board, word);
}