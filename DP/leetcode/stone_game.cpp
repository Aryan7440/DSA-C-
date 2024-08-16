#include <bits/stdc++.h>
using namespace std;
// int util(vector<int> &piles, int chance, int ind, int M)
// {
//     if (ind >= piles.size())
//         return 0;
//     int res;
//     if (chance == 0) // alice
//     {
//         res = INT_MIN;
//         int sum = 0;

//         for (int i = ind; i < piles.size() && i <ind+ 2 * M; i++)
//         {
//             sum += piles[i];
//             res = max(res, util(piles, 1,  i + 1, max(M,i-ind+1)) + sum);
//         }
//     }
//     if (chance == 1) // BOB
//     {
//         res = INT_MAX;
//         int sum = 0;

//         for (int i = ind; i < piles.size() && i < ind+2 * M; i++)
//         {
//             sum += piles[i];
//             res = min(res, util(piles, 0, i + 1, max(M,i-ind+1))-sum);
//         }
//     }
//     return res;
// }
// int stoneGameII(vector<int> &piles)
// {
//     int diff= util(piles, 0, 0, 1);
//     int sum=accumulate(piles.begin(),piles.end(),0);
//     return ((sum-diff)/2 ) +diff;
// }

// int util(vector<int> &piles, int chance, int ind, int M, vector<vector<vector<int>>> &dp)
// {
//     if (ind >= piles.size())
//         return 0;
//     if (dp[chance][ind][M] != -1)return dp[chance][ind][M];
//     int res;
//     if (chance == 0) // alice
//     {
//         res = INT_MIN;
//         int sum = 0;

//         for (int i = ind; i < piles.size() && i < ind + 2 * M; i++)
//         {
//             sum += piles[i];
//             res = max(res, util(piles, 1, i + 1, max(M, i - ind + 1), dp) + sum);
//         }
//     }
//     if (chance == 1) // BOB
//     {
//         res = INT_MAX;
//         int sum = 0;

//         for (int i = ind; i < piles.size() && i < ind + 2 * M; i++)
//         {
//             sum += piles[i];
//             res = min(res, util(piles, 0, i + 1, max(M, i - ind + 1), dp));
//         }
//     }
//     return dp[chance][ind][M] = res;
// }
// int stoneGameII(vector<int> &piles)
// {
//     int n = piles.size();
//     vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(2*n, -1)));
//     return util(piles, 0, 0, 1, dp);
// }



int util(vector<int>&piles,int ind,int M,vector<int> &suffix_sum,vector<vector<int>>&dp)
{
    if(ind>=piles.size())return 0;
    if(ind+2*M>=piles.size()-1) return suffix_sum[ind];
    if(dp[ind][M]!=-1)return dp[ind][M];
    int res=0;
    for(int i=1;i<=2*M;i++)
    {
        res=max(res,suffix_sum[ind]-util(piles,ind+i,max(M,i),suffix_sum,dp));
    }
    return dp[ind][M]=res;
}
int stoneGameII(vector<int>&piles)
{  
    int n=piles.size();
    vector<int> suffix_sum(n+1,0);
    for(int i=n-1;i>=0;i--)
    {
        suffix_sum[i]=piles[i]+suffix_sum[i+1];
    }
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return util(piles,0,1,suffix_sum,dp);
}
int main()
{
    // vector<int> piles = {1};
    vector<int> piles = {2, 7, 9, 4, 4};
    cout << stoneGameII(piles);
}