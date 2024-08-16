#include <bits/stdc++.h>
using namespace std;

int minimumDifference(vector<int> &nums)
{
    int n=nums.size();
    int sum = 0;
    int m = 0;
    for (auto i : nums)
    {
        sum += i;
        if (i > 0)
            m += i;
    }
    vector<int> prev(m+1, 0);
    vector<int> curr(m + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (j == 0)
                curr[j] = 1;
            else if (i == 0)
            {
                if (nums[i] <= m)
                    curr[nums[i]] = 1;
            }
            else
            {
                int dont_take = prev[j];
                int take = (j - nums[i] < 0) ? 0 : prev[j - nums[i]];
                curr[j] = take || dont_take;
            }
        }
        prev = curr;
    }
    int ans = INT_MAX;
    for(int i=0;i<sum/2+1;i++)
    {
        if(curr[i]==1)
            ans=min(ans,abs(i-(sum-i)));
    }
    return ans;
}
int main()
{
    vector<int> nums = {2,-1,0,4,-2,-9};
    cout<< minimumDifference(nums);
}