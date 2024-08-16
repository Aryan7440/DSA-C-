#include <bits/stdc++.h>
using namespace std;

int help(vector<int> &nums, int k)
{
    if (k <= 0 || nums.size() == 0)
        return 0;
    int i = 0, j = 0, count = 0, sum = 0;
    while (j < nums.size())
    {
        sum += nums[j];
        while (sum > k)
        {
            sum -= nums[i];
            i++;
        }
        count += j - i + 1;
        j++;
    }
    return count;
}
int subarraySum1(vector<int> &nums, int k)
{
    return help(nums, k) - help(nums, k - 1);
}

int subarraySum2(vector<int>&nums,int k)
{
    int prev_sum=0,res=0;
    unordered_map<int,int> mp;
    mp[0]=1;
    for(int i=0;i<nums.size();i++)
    {
        prev_sum+=nums[i];
        mp[prev_sum]++;
        if(mp.find(prev_sum-k)!=mp.end())res+=mp[prev_sum-k];
    }
    return res;
}
int main()
{
    vector<int> nums={3,9,-2,4,1,-7,2,6,-5,8,-3,-7,6,2,1};
    cout<<subarraySum2(nums,5);
}