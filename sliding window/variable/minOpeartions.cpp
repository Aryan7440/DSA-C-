#include<bits/stdc++.h>
using namespace std;
int minOperations(vector<int>& nums, int x) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int X=sum-x;
        int l=0,r=0,n=nums.size();
        sum=0;
        int ans=INT_MAX;
        while(r<n)
        {
            sum+=nums[r++];
            while(l<r && sum>X)sum-=nums[l++];

            if(sum==X)ans=min(ans,n-(r-l+1));
        }
        return ans==INT_MAX?-1:ans;
    }
    int main()
    {
        vector<int> nums={1,1,4,2,3};
        cout<<minOperations(nums,5);
    }