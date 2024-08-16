#include <bits/stdc++.h>
using namespace std;
int util(vector<int> &nums, int k, vector<vector<int>> &dp, int ind)
{
    if (ind == nums.size())
    {
        if (k == 0)
            return 1;
        else
            return 0;
    }
    if (dp[ind][k] != -1)
        return dp[ind][k];
    int take = (k - nums[ind] < 0) ? 0 : util(nums, k - nums[ind], dp, ind + 1);
    int dont_take = util(nums, k, dp, ind + 1);
    return dp[ind][k] = take + dont_take;
}
void count_subsets(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    
    // return util(nums, k, dp, 0);
    
    dp[0][0]=1;
    dp[0][nums[0]]=1;
    if(nums[0]==0)dp[0][nums[0]]=2;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<k+1;j++)
        {
            int take=(j-nums[i]>=0)?dp[i-1][j-nums[i]]:0;
            int dont_take=dp[i-1][j];
            dp[i][j]=take+dont_take;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k+1;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main()
{
    // vector<int> arr = {2,3,5, 6, 8, 10};
    // cout<<count_subsets(arr,10);
    // count_subsets(arr,10);
    vector<int> arr = {0,0,0,0,0,0,0,0,1};
    count_subsets(arr,1);
    // cout<<count_subsets(arr,1);
    // vector<int> arr = {1,0,0,0,0,0,0,0,0};
    // count_subsets(arr,1);
    // cout<<count_subsets(arr,1);
    // vector<int> arr = {9, 7, 0, 3, 9, 8, 6, 5, 7, 6};
    // count_subsets(arr,31);
    // cout<<count_subsets(arr,31);

    
}