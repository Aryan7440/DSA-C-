#include <bits/stdc++.h>
using namespace std;
void longestPalindrome(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int max_len = 0;
    string ans;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
                dp[i][j] = 1;
            else
            {
                if ((dp[i + 1][j - 1] && s[i] == s[j]) || (j == i + 1 && s[i] == s[j]))
                {
                    dp[i][j] = 1;
                    if (max_len < j - i + 1)
                    {
                        max_len = j - i + 1;
                        ans = s.substr(i, max_len);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    // return ans;
}
int main()
{
    string s = "aaaaaaaaaaaaaaaaaaaaaa";
    // string s="cbbd";
    longestPalindrome(s);
}