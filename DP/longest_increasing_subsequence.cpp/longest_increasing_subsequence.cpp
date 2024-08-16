#include<bits/stdc++.h>
using namespace std;

int util(vector<int>&nums,int ind,int prev_ind,vector<vector<int>> &dp)
{
    if(ind==nums.size())return 0;
    if(dp[ind+1][prev_ind+1]!=-1)return dp[ind+1][prev_ind+1];
    int take=0;
    if(prev_ind==-1 || nums[ind]>nums[prev_ind])
    {
        take=util(nums,ind+1,ind,dp)+1;
    }
    int not_take=util(nums,ind+1,prev_ind,dp);
    return dp[ind+1][prev_ind+1]=max(take,not_take);
}
int lengthOfLIS(vector<int> &nums)
{
    int n=nums.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    // return util(nums,0,-1,dp);
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j>=-1;j--)
        {
            int take=0;
            if(j==-1 || nums[i]>nums[j])
            {
                take=dp[i+1][i+1]+1;
            }
            int not_take=dp[i+1][j+1];
            dp[i][j+1]=max(take,not_take);
        }
    }
    return dp[0][0];
}
int main()
{
    vector<int> nums={3,5,6,2,5,4,19,5,6,7,12};
    cout<<lengthOfLIS(nums);
}