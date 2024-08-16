#include <bits/stdc++.h>
using namespace std;
// int util(vector<int> &arr1, vector<int> &arr2, int ind)
// {
//     if (ind == arr1.size() - 1)
//     {
//         if (arr1[ind] > arr1[ind - 1])
//             return 0;
//         else
//         {
//             int ub = upper_bound(arr2.begin(), arr2.end(), arr1[ind] + 1) - arr2.begin();
//             if (ub < arr2.size() && ub >= 0)
//                 return 1;
//             else
//                 return -1;
//         }
//     }
//     int ans = 0;
//     if (arr1[ind] >= arr1[ind + 1] || arr1[ind]<=arr1[ind-1])
//     {
//         int ub = upper_bound(arr2.begin(), arr2.end(), arr1[ind - 1]) - arr2.begin();
//         if (ub < 0 || ub==arr2.size() )
//             return -1;
//         ans = 1;
//         arr1[ind]=arr2[ub];
//     }
//     int res = util(arr1, arr2, ind + 1);
//     if (res == -1)
//         return -1;
//     return ans + res;
// }

int util(vector<int> &arr1, vector<int> &arr2, int i,int j,vector<unordered_map<int,int>>&dp)
{
    if(i==arr1.size())return 0;
    if(dp[i].find(j)!=dp[i].end())return dp[i][j];

    int replace=INT_MAX-1;
    int ub=upper_bound(arr2.begin(),arr2.end(),j+1)-arr2.begin();
    if(ub<arr1.size())replace=1+util(arr1,arr2,i+1,arr2[ub],dp);
    int move=INT_MAX/2;
    if(arr1[i]>j)util(arr1,arr2,i+1,arr1[i],dp);
    return dp[i][j]=min(replace,move);
}
int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
{
    sort(arr2.begin(), arr2.end());
    int n=arr1.size();
    vector<unordered_map<int,int>> dp(n);
    int ans=util(arr1, arr2, 0,INT_MAX,dp);
    return ans>=INT_MAX-1?-1:ans;
}

int main()
{
    vector<int> arr1 = {5,16,19,2,1,12,7,14,5,16}, arr2 = {6,17,4,3,6,13,4,3,18,17,16,7,14,1,16};
    // vector<int> arr1 = {0,11,6,1,4,3}, arr2 = {5,4,11,10,1,0};
    // vector<int> arr1 = {1,5,3,6,7}, arr2 = {1,6,3,3};
    cout<<makeArrayIncreasing(arr1,arr2);

}