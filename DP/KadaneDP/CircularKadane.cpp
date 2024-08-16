#include <bits/stdc++.h>
using namespace std;

int CircularKadane(vector<int> nums)
{
    int n = nums.size();
    int minEndingAt = nums[0], maxEndingAt = nums[0];
    int total = nums[0];
    int maxSubArray = nums[0];
    int minSubArray = nums[0];

    for (int i = 1; i < n; i++)
    {
        minEndingAt = min(minEndingAt + nums[i], nums[i]);
        minSubArray = min(minSubArray, minEndingAt);

        maxEndingAt = max(maxEndingAt + nums[i], nums[i]);
        maxSubArray = max(maxSubArray, maxEndingAt);
        total += nums[i];
    }

    if (minSubArray == total)
        return maxSubArray;

    return max(maxSubArray, total - minSubArray);
}

int main()
{
    vector<int> nums = {1, -2, 3, -1, 2};
    int result = CircularKadane(nums);
    cout << "Maximum sum of a circular subarray: " << result << endl;

    return 0;
}