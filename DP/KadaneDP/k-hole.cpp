#include <bits/stdc++.h>
using namespace std;
void kHole(vector<int> &nums)
{
    int n = nums.size();
    vector<int> MaxSubSeqenceSumEndingAtIndex(n, 0);
    MaxSubSeqenceSumEndingAtIndex[0] = max(0, nums[0]);
    for (int i = 1; i < n; i++)
    {
        MaxSubSeqenceSumEndingAtIndex[i] = max(MaxSubSeqenceSumEndingAtIndex[i - 1] + nums[i], MaxSubSeqenceSumEndingAtIndex[i - 1]);
    }
    cout << MaxSubSeqenceSumEndingAtIndex[n - 1] << endl;
}
int main()
{
    vector<int> nums = {1, -2, 3, -1, 2};
    kHole(nums);
    vector<int> nums1 = {1, 2, 3, -100, 3, 2};
    kHole(nums1);
    vector<int> num2 = {-1, -2, -3, -4, -5};
    kHole(num2);
    vector<int> num3 = {2, 3, 7, 8, 14, 39, 145, 76, 320};
    kHole(num3);
    return 0;
}