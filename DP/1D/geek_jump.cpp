#include <bits/stdc++.h>
using namespace std;

int util(vector<int> &height, vector<int> &dp, int n) //memoisation
{
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = min(util(height, dp, n - 1) + abs(height[n] - height[n - 1]), util(height, dp, n - 2) + abs(height[n] - height[n - 2]));
}
// int minimumEnergy(vector<int> &height, int n)
// {
//     // Code here
//     vector<int> dp(n + 2, -1);
//     dp[0] = 0;
//     dp[1] = abs(height[1]-height[0]);
//     if (n < 2)
//         return dp[n];
//     return util(height,dp,n-1);
// }
int minimumEnergy(vector<int> &height, int n)  //constant space
{
    // Code here
    if (n <= 1)
        return 0;
    int i = 0;
    int j = abs(height[1] - height[0]);
    int k = 2;
    while (k < n)
    {
        int temp = i;
        i = j;
        j = min(abs(height[k - 1] - height[k]) + j, abs(height[k - 2] - height[k]) + temp);
        k++;
    }
    return j;
}
int main()
{
    vector<int> height = {10, 20, 30, 10};
    cout << minimumEnergy(height, 3);
}