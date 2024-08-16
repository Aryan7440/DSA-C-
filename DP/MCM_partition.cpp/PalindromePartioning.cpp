#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> memPalindrome(string &s)
{
    int n = s.size();
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, true));
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int l = j - i;
            int r = j;
            if (l >= r)
            {
                isPalindrome[l][r] = true;
            }
            else if (s[l] == s[r])
            {
                isPalindrome[l][r] = isPalindrome[l + 1][r - 1];
            }
            else
            {
                isPalindrome[l][r] = false;
            }
        }
    }
    return isPalindrome;
}
int PP(string &str, int ind, vector<int> &dp, vector<vector<bool>> &isPalindrome)
{
    if (ind >= str.size())
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int res = INT_MAX;
    for (int i = ind; i < str.size(); i++)
    {
        if (isPalindrome[ind][i])
            res = min(res, 1 + PP(str, i + 1, dp, isPalindrome));
    }
    return dp[ind] = res;
}
int palindromicPartition(string str)
{
    int n = str.size();
    vector<vector<bool>> isPalindrome = memPalindrome(str);
    vector<int> dp(n, -1);
    return PP(str, 0, dp, isPalindrome) - 1;
}
int main()
{
    string str = "ababbbabbababa";
    int n = str.size();
    cout << palindromicPartition(str) << endl;

    // vector<vector<int>> isPalindrome(n, vector<int>(n, -1));
    // memPalindrome(str, 0, str.size() - 1, isPalindrome);
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (j < i)
    //             cout << "1 ";
    //         else
    //             cout << isPalindrome[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}