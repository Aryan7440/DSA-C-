#include <bits/stdc++.h>
using namespace std;
int longestPalindromeSubseq(string s)
{
    int n = s.size();
    reverse(s.begin(), s.end());
    string p = s;
    reverse(s.begin(), s.end());
    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == p[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return curr[n];
}
void print_longest_palindrome(string s)
{
    string p;
    int n = s.size();
    reverse(s.begin(), s.end());
    p = s;
    reverse(s.begin(), s.end());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int res = 0;
            if (s[i - 1] == p[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    cout << "    ";
    for (int i = 0; i < n; i++)
        cout << s[i] << " ";
    cout << endl;
    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
            cout << "  ";
        else
        {
            cout << p[i - 1] << " ";
        }
        for (int j = 0; j <= n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    int i = n, j = n;
    string ans1 = "";
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == p[j - 1])
        {
            ans1.push_back(s[i - 1]);
            i--;
            j--;
        }
        else if(dp[i][j-1]>dp[i-1][j])
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    cout<<ans1;
    
}
int main()
{
    string s = "aabba";
    print_longest_palindrome(s);
}