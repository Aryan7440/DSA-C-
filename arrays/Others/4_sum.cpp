#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int i = 0;
    while (i < n)
    {
        int j = i + 1;
        long long int remain1=target-nums[i];
        while (j < n)
        {
            int l = j + 1, r = n - 1;
            long long remain2=remain1-nums[j];
            while (l < r)
            {
                long long two_sum=nums[l]+nums[r];
                if (remain2 == two_sum)
                {
                    ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < n && nums[l] == nums[l - 1])
                        l++;
                    while (r > 0 && nums[r] == nums[r + 1])
                        r--;
                }
                else if (remain2 < two_sum)
                {
                    r--;
                    while (r > 0 && nums[r] == nums[r + 1])
                        r--;
                }
                else
                {
                    l++;
                    while (l < n && nums[l] == nums[l - 1])
                        l++;
                }
            }
            j++;
            while (j < n && nums[j] == nums[j - 1])
                j++;
        }
        i++;
        while (i < n && nums[i] == nums[i - 1])
            i++;
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> ans = fourSum(nums, 0);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}