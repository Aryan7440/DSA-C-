#include <bits/stdc++.h>
using namespace std;
int kadane(vector<int> &nums)
{
    int n = nums.size();
    vector<int> sumEndingAtIndex(n, INT_MIN);
    int maxSubArraySum = nums[0];
    sumEndingAtIndex[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        sumEndingAtIndex[i] = max(sumEndingAtIndex[i - 1] + nums[i], nums[i]);
        maxSubArraySum = max(maxSubArraySum, sumEndingAtIndex[i]);
    }
    return maxSubArraySum;
}
int kadaneOP(vector<int> &nums)
{
    int n = nums.size();
    int maxSubArraySum = nums[0];
    int sumEndingAtIndex = nums[0];
    for (int i = 1; i < n; i++)
    {
        sumEndingAtIndex = max(sumEndingAtIndex + nums[i], nums[i]);
        maxSubArraySum = max(maxSubArraySum, sumEndingAtIndex);
    }
    return maxSubArraySum;
}
int main()
{
    vector<int> nums1 = {1, 2, 3, 4, 5};
    cout << "Max subarray sum: " << kadaneOP(nums1) << endl;

    vector<int> nums2 = {-1, -2, -3, -4, -5};
    cout << "Max subarray sum: " << kadaneOP(nums2) << endl;

    vector<int> nums3 = {1, -2, 3, -4, 5};
    cout << "Max subarray sum: " << kadaneOP(nums3) << endl;
    vector<int> nums4 = {1, 3, -2, 7, -1};
    cout << "Max subarray sum: " << kadaneOP(nums4) << endl;
}