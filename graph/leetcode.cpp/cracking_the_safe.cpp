#include <bits/stdc++.h>
using namespace std;
bool dfs(int n, char k, int maxSize, string &state, unordered_set<string> &set)
{
    if (state.size() >= n && set.find(state.substr(state.size() - n)) != set.end())
        return false;
    if (state.size() >= n)
        set.insert(state.substr(state.size() - n));
    if (state.size() == maxSize)
        return true;

    for (char i = '0'; i <= k; i++)
    {
        state.push_back(i);
        if (dfs(n, k, maxSize, state, set))
            return true;
        state.pop_back();
    }
    if (state.size() >= n)
        set.erase(state.substr(state.size() - n));
    return false;
}
string crackSafe(int n, int k)
{
    int maxSize = (n - 1) + pow(k, n);
    unordered_set<string> set;
    string state = "";
    char K = to_string(k - 1)[0];
    dfs(n, K, maxSize, state, set);
    return state;
}

int main()
{
    cout << crackSafe(2, 2);
    return 0;
}