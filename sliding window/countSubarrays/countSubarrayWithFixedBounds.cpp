#include <bits/stdc++.h>
using namespace std;
int countSubarrayFixedBounds(vector<int> &nums, int maxK, int minK)
{
    int n = nums.size();
    int bi = -1, mai = -1, mii = -1;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > maxK || nums[i] < minK)
            bi = i;
        if (nums[i] == minK)
            mii = i;
        if (nums[i] == maxK)
            mai = i;
        cout << bi << " " << min(mii, mai) << endl;
        res += max(0, min(mii, mai) - bi);
    }
    return res;
}
int main()
{
    vector<int> nums = {1, 3, 5, 2, 7, 5};
    int maxK = 5, minK = 1;
    cout << countSubarrayFixedBounds(nums, maxK, minK);
    return 0;
}