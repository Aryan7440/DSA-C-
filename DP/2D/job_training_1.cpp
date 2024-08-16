#include <bits/stdc++.h>
using namespace std;
int util(vector<vector<int>> &points, int n, int day, int sport, vector<vector<int>> &dp)
{
    if (day >= n)
        return 0;
    if (dp[day][sport] != -1)
        return dp[day][sport];
    int temp = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i == sport)
            continue;
        temp = max(temp, util(points, n, day + 1, i, dp) + points[day][sport]);
    }
    return dp[day][sport] = temp;
}
int maximumPoints(vector<vector<int>>&points,int n)//space optimization
{
    int a=points[0][0],b=points[0][1],c=points[0][2];
    for(int i=1;i<n;i++)
    {
        int a_=max(b,c)+points[i][0];
        int b_=max(a,c)+points[i][1];
        int c_=max(b,a)+points[i][2];
        a=a_;
        b=b_;
        c=c_;
    }
    return max(a,max(b,c));
}
// int maximumPoints(vector<vector<int>> &points, int n) //tabulation
// {
//     // Code here
//     vector<vector<int>> dp(n + 1, vector<int>(4, -1));
//     dp[0][0] = points[0][0];
//     dp[0][1] = points[0][1];
//     dp[0][2] = points[0][2];
//     dp[0][3] = max(dp[0][0], max(dp[0][1], dp[0][2]));
//     for (int i = 1; i < n; i++)
//     {
//         int maxi = 0;
//         for (int j = 0; j < 3; j++)
//         {
//             int temp = 0;
//             for (int k = 0; k < 3; k++)
//             {
//                 if (k == j)
//                     continue;
//                 temp = max(temp, dp[i - 1][k]);
//             }
//             dp[i][j] = temp + points[i][j];
//             maxi = max(maxi, dp[i][j]);
//         }
//         dp[i][3] = maxi;
//     }
//     return dp[n - 1][3];
// }
// int maximumPoints(vector<vector<int>> &points, int n)  //memoisation
// {
//     vector<vector<int>> dp(n + 1, vector<int>(4, -1));
//     int ans = 0;
//     for (int i = 0; i < 3; i++)
//     {
//         ans = max(ans, util(points, n, 0, i, dp));
//     }
//     return ans;
// }
int main()
{
    vector<vector<int>> points = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    cout << maximumPoints(points, 3);
}