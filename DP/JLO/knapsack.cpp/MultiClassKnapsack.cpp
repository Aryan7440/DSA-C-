#include<bits/stdc++.h>
using namespace std;

int util(vector<vector<int>>&house,int ind,int W,vector<vector<int>>& dp)
{
    if (ind == house.size() || W == 0)
    {
        return 0;
    }
    if(dp[ind][W]!=-1)
    {
        return dp[ind][W];
    }
    int res=0;
    int nextInd = ind+1;
    while (nextInd < house.size() && house[nextInd][2] == house[ind][2])
    {
        nextInd++;
    }
    for(int i=ind;i<nextInd;i++)
    {
        if (W >= house[i][1])
        {
            res = max(res, house[i][0] + util(house, nextInd, W - house[i][1], dp));
        }
    }
    res=max(res,util(house,nextInd,W,dp));
    return dp[ind][W]=res;
}
int MaxProfit(vector<int>&profit,vector<int>&size,vector<int>&cls,int W)
{
    vector<vector<int>> house;
    for(int i=0;i<profit.size();i++)
    {
        house.push_back({profit[i],size[i],cls[i]});
    }
    sort(house.begin(),house.end(),[](vector<int>&a,vector<int>&b){
        return a[2]<b[2];
    });
    vector<vector<int>> dp(house.size(),vector<int>(W+1,-1));
    return util(house,0,W,dp);
}
int main()
{
    vector<int> profit={10,5,15,7,6,18,3};
    vector<int> size={2,3,5,7,1,4,1};
    vector<int> cls={1,2,1,2,1,2,1};
    vector<vector<int>> dp(profit.size()+1,vector<int>(20,-1));
    cout<<MaxProfit(profit,size,cls,15)<<endl;
    return 0;
}