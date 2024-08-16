#include <bits/stdc++.h>
using namespace std;
int util(int ind, vector<vector<int>> &offers, vector<int> &dp)
{
    if (ind == offers.size())
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int take = offers[ind][2];
    int i = ind;
    // while(i<offers.size() && offers[i][0]<=offers[ind][1])i++;
    // take+=util(i,offers,dp);
    int l = ind, r = offers.size() - 1;
    int mid = l + (r - l) / 2;
    int ub = offers.size();
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (offers[mid][0] > offers[ind][1])
        {
            ub = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    take += util(ub, offers, dp);
    int not_take = util(ind + 1, offers, dp);
    return dp[ind] = max(take, not_take);
}
int maximizeTheProfit(int n, vector<vector<int>> &offers)
{
    sort(offers.begin(), offers.end());
    vector<int> dp(offers.size(), -1);
    return util(0, offers, dp);
}
int main()
{
    int n = 5;
    vector<vector<int>> offers = {{0,0,1},{0,2,2},{1,3,2}};
    cout<<maximizeTheProfit(n,offers);
}