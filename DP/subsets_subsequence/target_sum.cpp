#include <bits/stdc++.h>
using namespace std;
int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if ((sum + target) % 2 != 0 || sum + target < 0)
        return 0;
    int k = abs((sum + target) / 2);
    vector<int> prev(k + 1, 0);
    vector<int> curr(k + 1, 0);
    prev[0] = 1;
    if (nums[0] <= k)
        prev[nums[0]] = 1;
    if (nums[0] == 0)
        prev[0] = 2;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < k + 1; j++)
        {
            int take = ((j - nums[i]) >= 0) ? prev[j - nums[i]] : 0;
            int dont_take = prev[j];
            curr[j] = take + dont_take;
        }
        prev = curr;
    }
    return prev[k];
}
int main()
{
    vector<int> nums = {1000};
    cout << findTargetSumWays(nums, -1000);
}