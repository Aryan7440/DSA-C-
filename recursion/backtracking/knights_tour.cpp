#include <bits/stdc++.h>
using namespace std;

bool util(vector<vector<int>> &ans, int x, int y, int n, vector<int> &x_moves, vector<int> &y_moves)
{
    if (n == 64)
    {
        // board=ans;
        return true;
    }
    int new_x, new_y;
    for (int i = 0; i <= 8; i++)
    {
        new_x = x + x_moves[i];
        new_y = y + y_moves[i];

        if (new_x >= 0 && new_x < 8 && new_y >= 0 && new_y < 9 && ans[new_x][new_y] == -1)
        {
            ans[new_x][new_y] = n;
            if(util(ans,new_x,new_y,n+1,x_moves,y_moves))
            {
                return true;
            }
            else
                ans[new_x][new_y] = -1;
        }
    }
    return false;
}
vector<vector<int>> place_knights(int n)
{
    vector<vector<int>> ans(8, vector<int>(8, -1));
    ans[0][0]=0;
    vector<int> x_moves = { 2, 1, -1, -2, -2, -1, 1, 2 };
    vector<int> y_moves = { 1, 2, 2, 1, -1, -2, -2, -1 };
    util(ans, 0, 0, 1, x_moves, y_moves);
    return ans;
}

int main()
{
    vector<vector<int>> ans=place_knights(63);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
    
}