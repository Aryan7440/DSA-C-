#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<int> topoSort(vector<vector<int>> &graph, vector<int> &indegree)
{
    int n = graph.size();
    vector<int> ans;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto &nbr : graph[node])
        {
            indegree[nbr]--;
            if (indegree[nbr] == 0)
            {
                q.push(nbr);
            }
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    vector<vector<int>> graph(26);
    vector<int> indegree(26, 0);
    for (int i = 0; i < n - 1; i++)
    {
        string word1 = words[i];
        string word2 = words[i + 1];
        int j = 0;
        while (j < word1.size() && j < word2.size() && word1[j] == word2[j])
        {
            j++;
        }
        if (j < word1.size() && j < word2.size())
        {
            graph[word1[j] - 'a'].push_back(word2[j] - 'a');
            indegree[word2[j] - 'a']++;
        }
        else if (j == word2.size() && word2.size() < word1.size())
        {
            cout << "Impossible";
            return 0;
        }
    }
    vector<int> ans = topoSort(graph, indegree);
    for (int i = 0; i < 26; i++)
    {
        if (indegree[i] > 0)
        {
            cout << "Impossible";
            return 0;
        }
    }
    unordered_set<int> st(ans.begin(), ans.end());
    for (int i = 0; i < 26; i++)
    {
        if (st.find(i) == st.end())
        {
            ans.push_back(i);
        }
    }
    for (int i = 0; i < 26; i++)
    {
        cout << char(ans[i] + 'a');
    }
}