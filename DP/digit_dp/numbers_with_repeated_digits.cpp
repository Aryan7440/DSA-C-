#include <bits/stdc++.h>
using namespace std;
int dp[11][2][2][1 << 10];
int help(string &num, int ind, int tight, int flag, int mask)
{
    if (ind == num.size())
        return flag != 0;
    if (dp[ind][tight][flag][mask] != -1)
        return dp[ind][tight][flag][mask];
    int limit = tight ? num[ind] - '0' : 9;
    int res = 0;

    for (int i = 0; i <= limit; i++)
    {
        if (i == 0 && mask == 0)
            res += help(num, ind + 1, tight && i == limit, flag, mask);
        else
            res += help(num, ind + 1, tight && i == limit, flag || ((1 << i) & mask), mask | (1 << i));
    }
    return dp[ind][tight][flag][mask] = res;
}
int numDupDigitsAtMostN(int n)
{
    memset(dp, -1, sizeof(dp));
    string num = to_string(n);
    return help(num, 0, 1, 0, 0);
}
int main()
{
    cout << numDupDigitsAtMostN(124);
}