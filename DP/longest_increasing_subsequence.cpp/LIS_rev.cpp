#include <bits/stdc++.h>
using namespace std;
int util(vector<int> &nums, int ind, int p_ind)
{
    if (ind >= nums.size())
        return 0;

    int take = 0;
    if (nums[ind] > nums[p_ind] || p_ind == -1)
    {
        take = 1 + util(nums, ind + 1, ind);
    }
    int not_take = util(nums, ind + 1, p_ind);
    return max(take, not_take);
}
void LIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> hash(n, 0);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[i] < dp[j] + 1 && nums[i] > nums[j])
            {
                dp[i] = dp[j] + 1;
                if (dp[ans] < dp[i])
                {
                    ans = i;
                }
                hash[i] = j;
            }
        }
    }
    cout << ans << endl;

    int ind = 1;
    vector<int> res(dp[ans]);
    res[0] = nums[ans];
    while (ans != hash[ans])
    {
        ans = hash[ans];
        res[ind++] = nums[ans];
    }
    for (auto i : res)
        cout << i << " ";
    // cout << dp[0][-1 + 1] << endl;
    // // cout << util(nums, 0, -1);
    // cout << "   ";
    // for (int j = 0; j < n + 1; j++)
    // {
    //     cout << j - 1 << "   ";
    // }
    // cout << endl;
    // for (int i = 0; i < n + 1; i++)
    // {
    //     cout << i << "   ";
    //     for (int j = 0; j < n + 1; j++)
    //     {
    //         cout << dp[i][j] << "   ";
    //     }
    //     cout << endl;
    // }
}
int main()
{
    vector<int> nums = {3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12}; // 2  4  5  6  7  12
    // lengthOfLIS(nums);
    LIS(nums);
}