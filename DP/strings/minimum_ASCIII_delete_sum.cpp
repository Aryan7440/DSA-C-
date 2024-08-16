#include <bits/stdc++.h>
using namespace std;
// vector<int> prefix_i, prefix_j;
// int util(string s1, string s2, int i, int j, vector<vector<int>> &dp)
// {
//     if (i == s1.size())
//         return prefix_j[j];
//     if (j == s2.size())
//         return prefix_i[i];
//     if (dp[i][j] != -1)
//         return dp[i][j];

//     int res = INT_MAX;
//     if (s1[i] == s2[j])
//     {
//         res = util(s1, s2, i + 1, j + 1, dp);
//     }
//     res = min(res, util(s1, s2, i + 1, j, dp) + s1[i]);
//     res = min(res, util(s1, s2, i, j + 1, dp) + s2[j]);
//     return dp[i][j] = res;
// }
// int minimumDeleteSum(string s1, string s2)
// {
//     int n = s1.size(), m = s2.size();
//     prefix_i.resize(n + 1);
//     prefix_i[n] = 0;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         prefix_i[i] = prefix_i[i + 1] + s1[i];
//     }
//     prefix_j.resize(m + 1);
//     prefix_j[m] = 0;
//     for (int i = m - 1; i >= 0; i--)
//     {
//         prefix_j[i] = prefix_j[i + 1] + s2[i];
//     }
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
//     return util(s1, s2, 0, 0, dp);
// }
int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<int> prefix_i(n+1,0),prefix_j(m+1,0);
        for(int i=n-1;i>=0;i--)
        {
            prefix_i[i]=prefix_i[i+1]+s1[i];
        }
        for(int i=m-1;i>=0;i--)
        {
            prefix_j[i]=prefix_j[i+1]+s2[i];
        }
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return util(s1,s2,0,0,dp);
        for(int i=n;i>=0;i--)
        {
            for(int j=m;j>=0;j--)
            {
                if(i==n)dp[i][j]= prefix_j[j];
                else if(j==m)dp[i][j]=prefix_i[i];
                // else if(dp[i][j]!=-1)return dp[i][j];
                else
                {
                    int res=INT_MAX;
                    if(s1[i]==s2[j])
                    {
                        res=dp[i+1][j+1];
                    }
                    res=min(res,dp[i+1][j]+s1[i]);
                    res=min(res,dp[i][j+1]+s2[j]);
                    dp[i][j]=res;
                }  
            }
        }
        return dp[0][0];
    }
int main()
{
    string s1 = "delete", s2 = "leet";
    // string s1 = "sea", s2 = "eat";
    cout<<minimumDeleteSum(s1,s2);
}