#include <bits/stdc++.h>
using namespace std;
int util(vector<int> &height, int k, int n, vector<int> &dp)
{
    if (dp[n] != -1)
        return dp[n];
    int step = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
            step = min(step, abs(height[n] - height[n - i]) + util(height, k, n - i, dp));
    }
    return dp[n] = step == INT_MAX ? 0 : step;
}
int minimizeCost(vector<int> &height, int n, int k)
{
    // Code here
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    return util(height, k, n - 1, dp);
}
int main()
{
    vector<int> height={10 ,30 ,40, 50 ,20};
    cout<<minimizeCost(height,5,3);
}