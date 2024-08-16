#include <bits/stdc++.h>
using namespace std;
int help(string &num, int ind, int tight, int flag, vector<vector<vector<int>>> &dp)
{
    if (ind == num.size())
        return flag == 1;

    if (dp[ind][tight][flag] != -1)
        return dp[ind][tight][flag];
    int limit = tight ? num[ind] - '0' : 9;
    int res = 0;
    for (int i = 0; i <= limit; i++)
    {
        if (i == 3 || i == 4 || i == 7)
            continue;
        bool f = (i == 2 || i == 5 || i == 6 || i == 9);
        if (flag == 0 && f)
            res += help(num, ind + 1, tight && i == limit, 1, dp);
        else
            res += help(num, ind + 1, tight && i == limit, flag, dp);
    }
    return dp[ind][tight][flag] = res;
}
int rotatedDigits(int n)
{
    string num = to_string(n);
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
    return help(num, 0, 1, 0, dp);
}
int main()
{
    cout << rotatedDigits(242);
}