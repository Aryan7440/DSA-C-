#include <bits/stdc++.h>
using namespace std;
int subarraysDivByK(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;//can use vector of size k couse mod value will not increse above k
    mp[0] = 1;
    int pre = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        pre =(pre+ nums[i]%k+k);
        if (mp.find(pre % k) == mp.end())
            mp[pre % k]++;
        else
        {
            ans += mp[pre % k];
            mp[pre % k]++;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums={-1,2,9};
    cout<<subarraysDivByK(nums,2);
    // cout<<-1%2;
}