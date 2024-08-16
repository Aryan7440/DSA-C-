#include <bits/stdc++.h>
using namespace std;
int util(string word1, string word2, int i, int j, vector<vector<int>> &dp)
{
    if (i == word1.size())return word2.size()-j;
    if (j == word2.size())return word1.size()-i;
    if (dp[i][j] != -1)return dp[i][j];
    if(word1[i] == word2[j])return util(word1,word2,i+1,j+1,dp);
    int rep = util(word1, word2, i + 1, j + 1, dp);
    int ers = util(word1, word2, i+1, j, dp);
    int ins = util(word1, word2, i , j + 1, dp);

    return dp[i][j] = 1 + min(rep, min(ers, ins));
}
int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return util(word1, word2, 0, 0, dp);
}
int main()
{
    string word1="sea",word2="eat";
    cout<<minDistance(word1,word2);
}