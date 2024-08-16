#include <bits/stdc++.h>
using namespace std;
bool ispal(string &s, int i, int j)
{
    while (i <= j)
        if (s[i++] != s[j--])
            return false;
    return true;
}
int util(string &s, int i, vector<int> &dp)
{
    if (ispal(s, i, s.size() - 1))
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int ans = INT_MAX;
    for (int k = i; k < s.size(); k++)
    {
        if (ispal(s, i, k))
            ans = min(ans, 1 + util(s, k + 1, dp));
    }
    return dp[i] = ans;
}
int minCut(string s)
{
    int n = s.size();
    vector<int> dp(n, -1);
    // return util(s,0,dp);
    for (int i = n - 1; i >= 0; i--)
    {

        if (ispal(s, i, s.size() - 1))
        {
            dp[i] = 0;
        }
        else
        {
            int ans = INT_MAX;
            for (int k = i; k < s.size(); k++)
            {
                if (ispal(s, i, k))
                    ans = min(ans, 1 + dp[k + 1]);
            }
            dp[i] = ans;
        }
    }
    return dp[0];
}
int main()
{
    string s = "leet";
    cout << minCut(s);
}