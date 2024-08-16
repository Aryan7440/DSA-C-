#include <bits/stdc++.h>
using namespace std;
int maxSumWithNonAdjacentElements(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));
    // zero matlab ki nahi liya
    // one matlab ki liya hai
    dp[0][1] = nums[0];
    dp[0][0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = max(dp[i - 1][0] + nums[i], dp[i - 1][1]);
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
}
int maxSumWithNonAdjacentElementsOP(vector<int> &nums)
{
    int n = nums.size();
    int taking = nums[0];
    int notTaking = 0;
    for (int i = 1; i < n; i++)
    {
        int notTaking1 = max(notTaking, taking);
        int taking1 = max(notTaking + nums[i], taking);
        taking = taking1;
        notTaking = notTaking1;
    }
    return max(taking, notTaking);
}
int main()
{
    vector<int> nums = {5, 5, 10, 100, 10, 5};
    cout << maxSumWithNonAdjacentElements(nums) << endl;
}