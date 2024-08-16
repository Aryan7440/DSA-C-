#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &graph, int i, vector<int> &visited, int colour)
{
    visited[i] = colour;
    int next_colour = (colour == 1) ? 2 : 1;
    for (int j = 0; j < graph[i].size(); j++)
    {
        if (!visited[graph[i][j]])
        {
            if(!dfs(graph, graph[i][j], visited, next_colour))return false;
        }
        else
        {
            if (visited[graph[i][j]] != next_colour)
                return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
    vector<int> visited(graph.size(), 0);
    for (int i = 0; i < graph.size(); i++)
    {
        if (!visited[i])
        {
            if (dfs(graph, i, visited, 1) != true)
                return false;
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> graph={{3,4,6},{3,6},{3,6},{0,1,2,5},{0,7,8},{3},{0,1,2,7},{4,6},{4},{}};
    cout<<isBipartite(graph);
}