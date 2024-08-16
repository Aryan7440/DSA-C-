#include <bits/stdc++.h>
using namespace std;
int nCr(int n, int r, vector<vector<int>> &dp)
{
    if (r > n)
        return 0;
    if (r == 1 || r == n)
        return 1;
    if (dp[n][r] != -1)
        return dp[n][r];
    return dp[n][r] = nCr(n - 1, r - 1, dp) + nCr(n - 1, r, dp);
    // return nCr(n-1,r-1)+nCr(n-1,r);

    // int sum=1;
    // for(int i=1;i<=r;i++)
    // {
    //     sum=sum*(n-r+i)/i;
    // }
    // return sum;
}

vector<vector<int>> comb(int N, int R)
{
    vector<vector<int>> nCr(N + 1, vector<int>(N + 1, 0));
    nCr[0][0] = 1;
    for (int n = 1; n <= N; n++)
    {
        nCr[n][0]=1;
        for (int r = 1; r <= n; r++)
        {
            if (r > n)
                continue;
            else if (r == 1 || r == n)
                nCr[n][r] = 1;
            else
            {
                nCr[n][r] = nCr[n - 1][r - 1] + nCr[n - 1][r];
            }
        }
    }
    return nCr;
}
