#include <bits/stdc++.h>
using namespace std;
int help(string &num,vector<vector<vector<int>>> &dp, int ind, bool tight, int count)
{
    if (ind == num.size())
        return count;
        if(dp[ind][tight][count]!=-1)return dp[ind][tight][count];
    int limit = tight ? num[ind] - '0' : 9;
    int res = 0;
    for (int i = 0; i <= limit; i++)
    {
        res += help(num, dp,ind + 1, i == limit, count + (i == 1));
    }
    return dp[ind][tight][count]= res;
}
int countDigitOne(int n)
{
    vector<vector<vector<int>>> dp(10, vector<vector<int>>(2, vector<int>(10, -1)));
    string num = to_string(n);
    return help(num, dp, 0, 1, 0);
}
int main()
{
    cout<<countDigitOne(13);
}
