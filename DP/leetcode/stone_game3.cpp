#include <bits/stdc++.h>
using namespace std;
int util(vector<int> &stoneValue, vector<int> &dp, int ind)
{
    if (ind >= stoneValue.size())
        return 0;
    if (dp[ind] != INT_MAX)
        return dp[ind];

    int res = 0;
    int sum = 0;

    res = INT_MIN;
    for (int i = ind; i < stoneValue.size() && i < ind + 3; i++)
    {
        sum += stoneValue[i];
        res = max(res, sum - util(stoneValue, dp, i + 1));
    }
    return dp[ind] = res;
}

string stoneGameIII(vector<int> &stoneValue)
{
    int n = stoneValue.size();
    vector<int> dp(n, INT_MAX);
    int ans = util(stoneValue, dp, 0);
    if (ans > 0)
        return "Alice";
    else if (ans < 0)
        return "Bob";
    return "Tie";
}
int main()
{
    // vector<int> stoneValue = {1, 2, 3, 7};
    vector<int> stoneValue = {-1, -2, -3};
    cout << stoneGameIII(stoneValue);
}