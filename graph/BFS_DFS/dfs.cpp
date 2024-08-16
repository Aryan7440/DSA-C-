#include <bits/stdc++.h>
using namespace std;

void dfs_(vector<vector<int>> &mat, vector<int> &visited, int s, vector<int> &ans)//matrix
{
    visited[s] = 1;
    ans.push_back(s);
    for (int i = 0; i < mat[s].size(); i++)
    {
        if (mat[s][i] == 1)
        {
            if (!visited[i])
            {
                dfs_(mat, visited, i, ans);
            }
        }
    }
}
// void dfs_(vector<vector<int>> &mat, vector<int> &visited, int s, vector<int> &ans)
// {
//     visited[s] = 1;
//     ans.push_back(s);
//     for (auto i : mat[s])
//     {
//         if (!visited[i])
//         {
//             dfs_(mat, visited, i,ans);
//         }
//     }
// }

vector<int> DFS(vector<vector<int>> &mat)
{
    vector<int> visited(mat.size(), 0);
    vector<int> ans;
    for (int i = 0; i < mat.size(); i++)
    {
        if (!visited[i])
        {
            dfs_(mat, visited, i, ans);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> mat = {{0, 1, 1, 1, 1}, {1, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 0, 0, 0, 0}};
    // vector<vector<int>> mat = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<int> ans = DFS(mat);
    for (auto i : ans)
        cout << i << " ";
}