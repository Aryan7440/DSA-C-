#include <bits/stdc++.h>
using namespace std;
void longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    // return dp[n][m];
    cout << "    ";
    for (int i = 0; i < m; i++)
        cout << text2[i] << " ";
    cout << endl;
    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
            cout << "  ";
        else
        {
            cout << text1[i - 1] << " ";
        }
        for (int j = 0; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
// void dfs(vector<vector<int>>&dp,string text1,string text2,vector<string> &ans,int i,int j,int x,string s)
// {
//     if(text1[i]==text2[j])
//     {
//         // s.push_front(text1[i]);

//     }
// }
string print_lcs(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int x = dp[n][m];
    int i = n, j = m;
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            ans.push_back(text1[i - 1]);
            i--;
            j--;
        }
        else if (dp[i][j - 1] > dp[i - 1][j])
        {
            ans.push_back(text2[j - 1]);

            j--;
        }
        else
        {
            ans.push_back(text1[i - 1]);
            i--;
        }
    }
    while (i > 0)
    {
        ans.push_back(text1[i - 1]);
        i--;
    }
    while (j > 0)
    {
        ans.push_back(text2[j - 1]);
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    string s = "abac", t = "cab";
    // string s = "abb", t = "bba";
    // string  s = "rabbbit", t = "rabbit";
    longestCommonSubsequence(s, t);
    string str = print_lcs(s, t);
    cout << str << endl;
}