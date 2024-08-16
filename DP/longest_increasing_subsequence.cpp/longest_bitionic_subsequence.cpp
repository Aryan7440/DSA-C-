#include <bits/stdc++.h>
using namespace std;
int LongestBitonicSequence(vector<int> nums)
{
    // code here
    int n = nums.size();
    vector<int> dpi(n, 1);
    vector<int> dpd(n, 1);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i] && dpi[i] < dpi[j] + 1)
                dpi[i] = dpi[j] + 1;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (nums[j] < nums[i] && dpd[i] < dpd[j] + 1)
                dpd[i] = dpd[j] + 1;
        }
        ans = max(ans, dpi[i] + dpd[i] - 1);
    }
    return ans;
}
int main()
{
    vector<int> nums = {20, 7, 9, 6, 9, 21, 12, 3, 12, 16, 1, 27};
    // vector<int> nums={1,2,5,3,2};
    cout << LongestBitonicSequence(nums);
}