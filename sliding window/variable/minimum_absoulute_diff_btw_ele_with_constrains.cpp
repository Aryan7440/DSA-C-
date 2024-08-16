#include <bits/stdc++.h>
using namespace std;
int minAbsoluteDifference(vector<int> &nums, int x)
{
    int n = nums.size();
    int i = 0, j = 0;
    multiset<int> set(nums.begin(), nums.end());
    int ans = INT_MAX;
    while (j < n)
    {
        while (j - i < x)
            set.erase(set.find(nums[j++]));
        if (j == n)
            break;
        auto lb = set.lower_bound(nums[i]);
        auto ma = lb;
        if (lb != set.begin())
        {
            lb--;
            auto mi = lb;
            ans=min(ans,abs(nums[i]-*mi));
        }
        if (ma != set.end())
            ans = min(ans, abs(nums[i] - *ma));

        // set.insert(nums[i]);
        i++;
    }
    return ans;
}
int main()
{
    // vector<int> nums={4,3,2,4};
    vector<int> nums = {97,8,189,194};
    // vector<int> nums = {71  ,4};
    // vector<int> nums = {13, 19, 12, 1};
    // vector<int> nums={1,2,3,4};
    cout << minAbsoluteDifference(nums, 2);
}