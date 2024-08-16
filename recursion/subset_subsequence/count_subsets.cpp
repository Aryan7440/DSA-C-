#include <bits/stdc++.h>
using namespace std;
int util(vector<int>&nums,int k,vector<vector<int>>&dp,int ind)
{
    if(ind==nums.size())
    {
        if(k==0)return 1;
        else return 0;
    }
    if(dp[ind][k]!=-1)return dp[ind][k];
    int take=(k-nums[ind]<0)?0:util(nums,k-nums[ind],dp,ind+1);
    int dont_take=util(nums,k,dp,ind+1);
    return dp[ind][k]=take+dont_take;

}
int count_subsets(vector<int>&nums,int k)
{
    int n=nums.size();
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return util(nums,k,dp,0);
}
int main()
{
    
}