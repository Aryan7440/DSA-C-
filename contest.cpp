#include <bits/stdc++.h>
using namespace std;
int dfs(int node, int parent, unordered_map<int, vector<int>> &graph, unordered_set<int> &visited)
{
    if (visited.count(node))
    {
        return 0;
    }

    visited.insert(node);

    int max_sum = node;

    for (int neighbor : graph[node])
    {
        if (neighbor == parent)
        {
            continue;
        }

        max_sum += dfs(neighbor, node, graph, visited);
    }

    visited.erase(node);

    return max_sum;
}
unordered_map<int, int> findMaxBranchSums(unordered_map<int, vector<int>> &graph)
{
    unordered_map<int, int> max_branch_sums;

    for (const auto &entry : graph)
    {
        int node = entry.first;

        unordered_set<int> visited;

        int max_sum = 0;
        for (int neighbor : graph[node])
        {
            max_sum = max(max_sum, dfs(neighbor, node, graph, visited));
        }

        max_branch_sums[node] = max_sum > 0 ? max_sum : node;
    }

    return max_branch_sums;
}
unordered_map<int, vector<int>> parseInput(const vector<string> &arr)
{
    unordered_map<int, vector<int>> graph;

    for (const string &s : arr)
    {
        int colon_pos = s.find(':');
        int node = stoi(s.substr(0, colon_pos));
        string neighbors_str = s.substr(colon_pos + 2, s.size() - colon_pos - 3);

        stringstream ss(neighbors_str);
        string item;
        while (getline(ss, item, ','))
        {
            int neighbor = stoi(item);
            graph[node].push_back(neighbor);
        }
    }

    return graph;
}
string GraphChallenge(string strArr[], int arrLength)
{
    vector<string> arr(strArr, strArr + arrLength);
    unordered_map<int, vector<int>> graph = parseInput(arr);
    unordered_map<int, int> max_branch_sums = findMaxBranchSums(graph);
    vector<pair<int, int>> results;
    for (const auto &entry : max_branch_sums)
    {
        results.push_back({entry.first, entry.second});
    }
    sort(results.begin(), results.end());
    string result = "";
    for (const auto &entry : results)
    {
        result += to_string(entry.first) + ":" + to_string(entry.second) + ",";
    }
    if (!result.empty())
    {
        result.pop_back();
    }

    return result;
}

int main()
{
    string A[] = coderbyteInternalStdinFunction(stdin);
    int arrLength = sizeof(A) / sizeof(A *);
    cout << GraphChallenge(A, 5) << endl;
    return 0;
}
