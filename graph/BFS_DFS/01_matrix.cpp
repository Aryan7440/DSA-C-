#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    queue<pair<int, int>> q;
    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, 1, 0, -1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] != 0)
                mat[i][j] = -1;
            else
            {
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int I = temp.first + di[i];
            int J = temp.second + dj[i];
            if (I >= 0 && I < n && J >= 0 && J < m && mat[I][J] == -1)
            {
                mat[I][J] = mat[temp.first][temp.second] + 1;
                q.push({I, J});
            }
        }
    }
    return mat;
}
int main()
{
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
    updateMatrix(mat);
    for(auto i:mat)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}