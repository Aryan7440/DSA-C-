#include <bits/stdc++.h>
using namespace std;

long long maxStrength(vector<int> &nums)
{
    int n=nums.size();
    vector<long long>pre(n,1);
    vector<long long> suf(n,1);
    pre[0]=1;
    suf[n-1]=1;
    for(int i=1;i<n;i++)
    {
        if(nums[i-1]==0)nums[i-1]=1;
        if(nums[n-i]==0)nums[n-i]=1;
        pre[i]=nums[i-1]*pre[i-1];
        suf[n-i-1]=nums[n-i]*suf[n-i];
    }
    long long ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        long long take=pre[i]*suf[i];
        long long not_take=take*nums[i];
        ans=max(ans,max(take,not_take));
    }
    
    return ans;
}
int main()
{
    vector<int> nums={2,2,7,0,-4,9,4};
    // vector<int> nums={3,-1,-5,2,5,-9};
    // 3  -3   15   30  150  -1350
    //-1350  -450   450 -90 -45    -9
    cout<<maxStrength(nums);
}