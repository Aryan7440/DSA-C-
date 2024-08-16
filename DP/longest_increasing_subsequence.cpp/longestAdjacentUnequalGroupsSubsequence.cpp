#include <bits/stdc++.h>
using namespace std;
bool ham(string s1, string s2)
{
    int c = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != s2[i])
            c++;
        if (c > 1)
            return false;
    }
    return c == 1;
}
vector<string> getWordsInLongestSubsequence(int n, vector<string> &words, vector<int> &groups)
{
    vector<int> dp(n, 1);
    vector<int> hash(n, 0);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (groups[j] != groups[i] && words[i].size() == words[j].size() && ham(words[i], words[j]) && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                if (dp[ans] < dp[i])
                {
                    ans = i;
                }
                hash[i] = j;
            }
        }
    }
    int ind = 1;
    vector<string> res(dp[ans]);
    res[0] = words[ans];
    while (ans != hash[ans] && ind < res.size())
    {
        ans = hash[ans];
        res[ind++] = words[ans];
    }
    // for (auto i : res)
    //     cout << i << " ";
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    int n = 3;
    vector<string> words = {"bdb", "aaa", "ada"};
    vector<int> groups = {2, 1, 3};
    vector<string> ans = getWordsInLongestSubsequence(n, words, groups);
}