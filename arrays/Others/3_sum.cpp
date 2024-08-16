#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> three_sum(vector<int> &nums, int sum)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int i = 0;
    while (i < nums.size())
    {
        int curr_sum = sum - nums[i];
        int l = i + 1, r = nums.size() - 1;
        while (l < r)
        {
            if (nums[l] + nums[r] == curr_sum)
            {
                vector<int> temp = {nums[i], nums[l], nums[r]};
                ans.push_back(temp);
                // break;
                l++;
                r--;
                while (nums[l] == nums[l - 1])
                    l++;
                while (nums[r] == nums[r + 1])
                    r--;
            }
            else if (nums[l] + nums[r] < curr_sum)
            {
                l++;
            }
            else
                r--;
        }
        i++;
        while (nums[i] == nums[i - 1])
            i++;
    }
    return ans;
}

int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int i = 0;
    int ans = nums[0]+nums[1]+nums[2];
    int n = nums.size();
    while (i < nums.size())
    {
        int l = i + 1, r = nums.size() - 1;
        while (l < r)
        {
            int curr_sum = nums[i] + nums[r] + nums[l];
            if (abs(target - curr_sum) < abs(target - ans))
            {
                ans = curr_sum;
            }
            if (curr_sum == target)
            {
                return target;
            }
            else if (l < n && curr_sum < target)
                l++;
            else
                r--;
        }
        i++;
        while (i < n && nums[i] == nums[i - 1])
            i++;
    }
    return ans;
}
int main()
{
    vector<int> nums = {-1,2,1,-4};
    cout<<threeSumClosest(nums,1);
    // vector<int> nums = {0, 0, 0};
    // vector<int> nums={-1,0,1,2,-1,-4};
    // vector<vector<int>> ans = three_sum(nums, 0);
    // for (auto i : ans)
    // {
    //     for (auto j : i)
    //         cout << j << " ";
    //     cout << endl;
    // }
}