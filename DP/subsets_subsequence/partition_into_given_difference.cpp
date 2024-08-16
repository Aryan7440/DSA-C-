#include <bits/stdc++.h>
using namespace std;
/*
s1=sum of subset 1
s2=sum of subset 2
s1-s2=d
s1+s2=sum of all elements

->> 2 x s1= d+sum
=>> s1=(d+sum)/2;
 i.e wee need to find number of subsets with sum =(s+total)/2
*/

int util(vector<int> &arr, int ind, int target, vector<vector<int>> &dp)
{
    if (target < 0)
        return 0;
    if (ind == arr.size())
    {
        if (target == 0)
            return 1;
        else
            return 0;
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];
    int take = (target - arr[ind] >= 0) ? util(arr, ind + 1, target - arr[ind], dp) : 0;
    int not_take = util(arr, ind + 1, target, dp);
    return dp[ind][target] = take + not_take;
}
int mod=1e9+7;
int countPartitions(int n, int d, vector<int> &arr)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if ((sum + d) % 2 != 0)
        return 0;
    int target = (d + sum) / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    // return util(arr,0,target,dp);
    dp[0][0] = 1;
    dp[0][arr[0]] = 1;
    if (arr[0] == 0)
        dp[0][0] = 2;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < target + 1; j++)
        {
            int take = (j - arr[i] >= 0) ? dp[i - 1][j - arr[i]] % mod : 0;
            int not_take = dp[i - 1][j] % mod;
            dp[i][j] = (take + not_take) % mod;
        }
    }
    return dp[n - 1][target];
}
int main()
{
    // vector<int> arr={ 5, 2, 6, 4};
    // cout<<countPartitions(4,3,arr);
    vector<int> arr = {1000};
    // vector<int> arr = {1, 1, 1, 1};
    cout << countPartitions(1, -1000, arr);
}