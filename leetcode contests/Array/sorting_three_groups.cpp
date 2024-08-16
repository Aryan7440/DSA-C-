#include<bits/stdc++.h>
using namespace std;
int util(vector<int>&nums,int ind,int prev,unordered_map<int,unordered_map<int,int>>dp)
{
    if(ind==nums.size())return 0;
    if(dp[ind].find(prev)!=dp[ind].end())return dp[ind][prev];
    int p=prev;
    if(prev==-1)p=1;
    int res=INT_MAX;
    for(int i=p;i<=3;i++)
    {
        res=min(res,util(nums,ind+1,i,dp)+(nums[ind]!=i));
    }
    return dp[ind][prev]= res;
}
int main()
{
    // vector<int> nums={2,2,2,2,3,3};
    // vector<int> nums={1,3,2,1,3,3};
    vector<int> nums={2,1,3,2,1};
    unordered_map<int,unordered_map<int,int>>dp;
    cout<<util(nums,0,-1,dp);
}