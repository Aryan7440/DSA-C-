#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
vector<int> mp = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
int util(string &pressedKeys, int ind, vector<int> &dp)
{
    if (ind == pressedKeys.size())
        return 1;
    if (dp[ind] != -1)
        return dp[ind];
    int not_take = 0;
    int i = 1;
    while ((ind + i < pressedKeys.size()) &&( pressedKeys[ind] == pressedKeys[ind + i] )&& (i < mp[pressedKeys[ind] - '0']))
    {
        not_take += util(pressedKeys, ind + i+1, dp) % mod;
        not_take = not_take % mod;
        i++;
        // int temp0=;
    }
    int take = util(pressedKeys, ind + 1, dp) % mod;
    return dp[ind] = (not_take + take) % mod;
}
int countTexts(string pressedKeys)
{
    int n = pressedKeys.size();
    vector<int> dp(n+1, 0);
    // return util(pressedKeys, 0, dp);
    for(int ind=n;ind>=0;ind--)
    {
        if (ind == n)dp[ind]= 1;
        else
        {
            int not_take = 0;
            int i = 1;
            while ((ind + i < pressedKeys.size()) &&( pressedKeys[ind] == pressedKeys[ind + i] )&& (i < mp[pressedKeys[ind] - '0']))
            {
                not_take += dp[ind+1+i] % mod;
                not_take = not_take % mod;
                i++;
                // int temp0=;
            }
            int take = dp[ind+1] % mod;
            dp[ind] = (not_take + take) % mod;
        }
    }
    return dp[0];
}
int main()
{
    string pressedKeys="22233";
    cout<<countTexts(pressedKeys);
}