#include <bits/stdc++.h>
using namespace std;
struct Comp
{
    bool operator()(string s1, string s2)
    {
        return s1.size() < s2.size();
    }
};
bool check(string s1, string s2)
{
    if (s1.size() + 1 != s2.size())
        return false;
    int l = 0, r = 0;
    int count = 0;
    while (l < s1.size() && r < s2.size())
    {
        if (s1[l] != s2[r])
        {
            count++;
            if (count > 1)
                return false;
            r++;
        }
        else
        {
            l++;
            r++;
        }
    }
    return s2.size() - r <= 1;
}
int longestStrChain(vector<string> &words)
{
    int n = words.size();
    sort(words.begin(), words.end(), Comp());
    vector<int> dp(n, 1);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (check(words[j], words[i]) && dp[j] + 1 > dp[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
int main()
{
    vector<string> v = {"a", "b", "ba", "bca", "bda", "bdca"};
    cout << longestStrChain(v);
    // cout << check("a", "b");
}