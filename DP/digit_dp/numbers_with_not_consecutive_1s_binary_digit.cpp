#include <bits/stdc++.h>
using namespace std;
int help(string &num,int ind,bool tight,bool flag,vector<vector<vector<int>>>&dp)
{
    if(ind==num.size())return 1;
    if(dp[ind][tight][flag]!=-1)return dp[ind][tight][flag];
    int limit=tight?num[ind]-'0':1;
    int res=0;
    for(int i=0;i<=limit;i++)
    {
        if(flag && i==1)continue;
        res+=help(num,ind+1,i==limit,i==1,dp);
    }
    return dp[ind][tight][flag]= res;
}
int findIntegers(int n)
{
    vector<vector<vector<int>>>dp(32,vector<vector<int>>(2,vector<int>(2,-1)));
    string num = bitset<32>(n).to_string();
    return help(num,0,1,0,dp);
}

int main()
{
    cout<<findIntegers(5);
}