#include <bits/stdc++.h>
using namespace std;
bool util(string s, unordered_set<string> &mp, int idx, vector<int> &dp)
{
    if (idx == s.size())
    {
        return true;
    }
    if (dp[idx] != -1)
        return dp[idx];
    int ans = 0;
    for (int i = idx; i < s.size(); i++)
    {
        string temp = s.substr(idx, i - idx + 1);
        if (mp.find(temp) != mp.end())
        {
            ans = ans || util(s, mp, i + 1, dp);
        }
    }
    return dp[idx] = ans;
}
void solve()
{
    int n;
    cin >> n;
    unordered_set<string> mp;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        mp.insert(s);
    }
    int m;
    cin >> m;
    string s;
    cin >> s;
    vector<int> dp(n, -1);
    if (util(s, mp, 0, dp))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
int main()
{
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}