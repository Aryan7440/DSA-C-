#include <bits/stdc++.h>
using namespace std;
int findMin(vector<int> &nums)
{
    int l = 0, n = nums.size(), r = n - 1;
    int ans = 0;
    int mid = l + (r - l) / 2;
    while (l <= r)
    {

        while (l + 1 < n && r > l && nums[l] == nums[l + 1])
            l++;
        while (r - 1 >= 0 && l < r && nums[r] == nums[r - 1])
            r--;
        // if(r<l)return nums[l];
        while (l < r && nums[l] == nums[r])
            r--;
        mid = l + (r - l) / 2;
        if (nums[mid] <= nums[r])
        {
            ans = nums[mid];
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}
int main()
{
    // vector<int> nums = {3,1,3};
    vector<int> nums = {2, 2, 2, 0, 1};
    cout << findMin(nums);
    // cout<<"aarnfwf,";
}
