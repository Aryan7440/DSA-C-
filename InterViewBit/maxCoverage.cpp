#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &nums, int B)
{
    int lastLit = -1;
    int lastBulb = -1;
    int n = nums.size();
    int maxCoverage = -1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i])
        {
            lastBulb = i;
        }
        if (i - B + 1 > maxCoverage)
        {
            lastLit = lastBulb;
            ans++;
            maxCoverage = lastLit + B - 1;
        }
        if (i > maxCoverage + B)
            return -1;
    }
    if (maxCoverage < n - 1)
        ans++;
    return ans;
};
int main()
{
    vector<int> nums = {0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0};
    int B = 12;
    cout << solve(nums, B);
    return 0;
}