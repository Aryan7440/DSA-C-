#include <bits/stdc++.h>
using namespace std;
int util(vector<int> &price, int ind, int rod,vector<vector<int>>&dp)
{
    int n = price.size();
    if (ind == 0)
    {
        return rod * price[0];
    }
    if(dp[ind][rod]!=-1)return dp[ind][rod];
    int take = INT_MIN;
    if (rod -(ind +1)>=0)
        take = price[ind] + util(price, ind, rod - (ind + 1),dp);
    int not_take = util(price, ind - 1, rod,dp);
    return dp[ind][rod]=max(take,not_take);
}
int cutRod(vector<int> &price)
{
    // code here
    int n = price.size();
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return util(price, n - 1, n,dp);
}
int main()
{
    vector<int> price = {3, 5, 8, 9, 10, 17, 17, 20};
    cout << cutRod(price);
}