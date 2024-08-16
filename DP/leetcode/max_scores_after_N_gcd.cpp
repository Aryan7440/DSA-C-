#include <bits/stdc++.h>
using namespace std;

// int gcd(int x, int y)
// {
//     if(x<y)return gcd(y,x);
//     if (y == 0)
//         return x;
//     return gcd(y, x % y);
// }
int util(vector<int> &nums, int op, int mask, vector<int> &dp, vector<vector<int>> &gcd)
{
    if (op > (nums.size() / 2))
        return 0;
    if (dp[mask] != -1)
        return dp[mask];
    for (int i = 0; i < nums.size(); i++)
    {
        if (mask & (1 << i))
            continue;

        for (int j = i + 1; j < nums.size(); j++)
        {
            if (mask & (1 << j))
                continue;
            int new_mask = mask | (1 << j) | (1 << i);
            int score = (op * gcd[i][j]) + util(nums, op + 1, new_mask, dp, gcd);
            dp[mask] = max(dp[mask], score);
        }
    }
    return dp[mask];
}
int maxScore(vector<int> &nums)
{
    vector<int> dp(1 << 14, -1);
    vector<vector<int>> gcd(nums.size(), vector<int>(nums.size(), 0));
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            gcd[i][j] = __gcd(nums[i], nums[j]);
        }
    }
    return util(nums, 1, 0, dp, gcd);
}
int main()
{

}