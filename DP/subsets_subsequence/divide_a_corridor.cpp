#include <bits/stdc++.h>
using namespace std;
// int mod = 1e9 + 7;
// int util(string corridor, int ind, vector<int> &dp)
// {
//     if (ind == corridor.size())
//         return 1;
//     if (dp[ind] != -1)
//         return dp[ind];

//     int l = ind;
//     int n = corridor.size();
//     int count = 0;
//     while (l < n && count != 2)
//     {
//         if (corridor[l] == 'S')
//             count++;
//         l++;
//     }
//     if (l == n)
//         return count < 2 ? 0 : 1;

//     int res = 0;
//     while (l < n)
//     {
//         res = ((res % mod) + (util(corridor, l, dp) % mod)) % mod;
//         if (corridor[l] == 'S')
//             break;
//         l++;
//     }
//     if (count == 2 && l == n)
//         return 1;
//     return dp[ind] = res;
// }

// int util(string corridor,int ind,vector<int>&dp)
// {
//     if()
// // }
// int numberOfWays(string corridor)
// {
//     int n = corridor.size();
//     vector<int> dp(n,-1);
//     return util(corridor,0,dp);
// vector<int> dp(n + 1, 0);
// for (int ind = n; ind >= 0; ind--)
// {
//     if (ind == n)
//         dp[ind] = 1;
//     else
//     {
//         int l = ind;
//         int count = 0;
//         while (l < n && count != 2)
//         {
//             if (corridor[l] == 'S')
//                 count++;
//             l++;
//         }
//         if (l == n)
//         {
//             dp[ind] = count < 2 ? 0 : 1;
//             continue;
//         }

//         int res = 0;
//         while (l < n)
//         {
//             res = ((res % mod) + (dp[l] % mod)) % mod;
//             if (corridor[l] == 'S')
//                 break;
//             l++;
//         }
//         if (count == 2 && l == n)
//         {
//             dp[ind] = 1;
//             continue;
//         }
//         dp[ind] = res;
//     }
// }
// return dp[0];
// }
int mod = 1e9 + 7;
int numberOfWays(string corridor)
{
    int count_s = 0, count_p = 0;
    int l = 0;
    int n = corridor.size();
    int ans = 0;
    int count = 1;
    while (l < n)
    {
        if (corridor[l] == 'S')
        {
            count_s++;
            if (count_s == 2)
            {
                l++;
                while (l < n && corridor[l] != 'S')
                {
                    count_p++;
                    l++;
                }
                if(l==n)count_p=0;
                count = ((count % mod) * ((count_p + 1) % mod)) % mod;
                count_s = 0;
                count_p = 0;
                continue;
            }
        }
        l++;
    }
    if (count_p != 0)
        return 0;
    return count;
}

int main()
{
    string corridor = "PPSPSP";
    // string corridor = "SSPPSPS";
    cout << numberOfWays(corridor);
}