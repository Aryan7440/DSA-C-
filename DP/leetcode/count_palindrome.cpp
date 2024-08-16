#include <bits/stdc++.h>
using namespace std;
long long int util(string str, int i, int j, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if(i==j)return dp[i][j]=1;
    if (str[i] == str[j])
    {
        return dp[i][j] = 1+util(str, i + 1, j, dp) + util(str, i, j - 1, dp) ;
    }
    return dp[i][j] = util(str, i + 1, j, dp) + util(str, i, j - 1, dp) - util(str, i + 1, j - 1, dp);
}
/*You are required to complete below method */
long long int countPS(string str)
{
    // Your code here
    int n = str.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return util(str, 0, n - 1, dp);
}

int main()
{
    string str="aaaaaaaaaaaaaaaaaaaaaaaaaaa";
    cout<<countPS(str);
}