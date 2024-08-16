#include <bits/stdc++.h>
using namespace std;

void dfs_(vector<vector<int>> &mat, vector<int> &visited, int s)
{
    visited[s] = 1;
    for (int i = 0; i < mat[s].size(); i++)
    {
        if (mat[s][i] == 1)
        {
            if (!visited[i])
            {
                dfs_(mat, visited, i);
            }
        }
    }
}
int numProvinces(vector<vector<int>> &adj, int V)
{
    // code here
    vector<int> visited(adj.size(), 0);
    int count = 0;
    for (int i = 0; i < adj.size(); i++)
    {
        if (!visited[i])
        {
            count++;
            dfs_(adj, visited, i);
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> mat = { {1, 0, 0, 0, 0},
                                {0, 1, 0, 0, 0},
                                {0, 0, 1, 0, 1},
                                {0, 0, 0, 1, 0},
                                {0, 0, 1, 0, 1} };
    cout<<numProvinces(mat,5);
}