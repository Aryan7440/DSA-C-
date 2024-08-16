#include <bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int> &nums, int k)
{
    int i = 0, j = 0, len = 0, sum = 0;
    unordered_map<int, int> mp;
    // mp[0] = 1;
    while (j < nums.size())
    {
        sum += nums[j];
        sum=sum%k;
        if(sum==0 && j>0)return true;
        if (mp.find(sum % k) != mp.end())
        {
            return true;
        }
        mp[sum % k]++;
        j++;
    }
    return false;
}
int main()
{
    // vector<int> nums={23,2,4,6,7};
    vector<int> nums={23,2,4,6,6};
    cout<<checkSubarraySum(nums,7);
}