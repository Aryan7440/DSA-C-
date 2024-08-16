#include <bits/stdc++.h>
using namespace std;

void hole(vector<int> &nums)
{
    int n = nums.size();
    vector<int> sumEndingAtIndex(n, 0);
    sumEndingAtIndex[0] = nums[0];
    vector<int> sumStartingAtIndex(n, 0);
    sumStartingAtIndex[n - 1] = nums[n - 1];
    for (int i = 1; i < n; i++)
    {
        sumEndingAtIndex[i] = max(sumEndingAtIndex[i - 1] + nums[i], nums[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        sumStartingAtIndex[i] = max(sumStartingAtIndex[i + 1] + nums[i], nums[i]);
    }
    int maxSum = max(sumEndingAtIndex[0], sumEndingAtIndex[n - 1]);
    for (int i = 1; i < n - 1; i++)
    {
        maxSum = max(maxSum, max(sumEndingAtIndex[i], sumEndingAtIndex[i - 1] + sumStartingAtIndex[i + 1]));
    }
    cout << "Maximum sum of a subarray with a hole: " << maxSum << endl;
}
int main()
{
    vector<int> nums = {1, -2, 3, -1, 2};
    hole(nums);
    vector<int> nums1 = {1, 2, 3, -100, 3, 2};
    hole(nums1);
    vector<int> num2 = {-1, -2, -3, -4, -5};
    hole(num2);
    return 0;
}