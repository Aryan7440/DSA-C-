#include <bits/stdc++.h>
using namespace std;

string findOrder(string dict[], int N, int K)
{
    vector<vector<int>> adj(K);
    for (int i = 0; i < N - 1; i++)
    {
        int p1 = 0, p2 = 0;
        while (p1 < dict[i].size() && p2 < dict[i + 1].size())
        {
            if (dict[i][p1] != dict[i + 1][p2])
            {
                adj[dict[i][p1] - 'a'].push_back(dict[i + 1][p2] - 'a');
                break;
            }
            p1++;
            p2++;
        }
    }
    // code here

    vector<int> indegree(K);
    for (int i = 0; i < K; i++)
    {
        for (int j = 0;j< adj[i].size(); j++)
            indegree[adj[i][j]]++;
    }
    queue<int> q;
    for (int i = 0; i < K; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    string topo;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        char c = temp + 'a';
        topo = topo + c;

        for (auto i : adj[temp])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }
    return topo;
}
int main()
{
    string dict[]= {"baa","abcd","abca","cab","cad"};
    cout<<findOrder(dict,5,4);
}