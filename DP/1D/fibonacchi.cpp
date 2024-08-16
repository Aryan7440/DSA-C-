#include <bits/stdc++.h>
using namespace std;

int fib(int x, vector<int> &dp)         //recursion +memoisation
{
    if (x <= 1)
        return dp[x] = x;
    if (dp[x] == -1)
        return dp[x] = fib(x - 1, dp) + fib(x - 2, dp);
    else
        return dp[x];
}

int fib_tab(int x)       //tabulation
{
    vector<int> dp(x+1,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<x+1;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[x];
}

int f(int x)//space optimisation
{
    int prev=0;
    int curr=1;
    for(int i=2;i<x+1;i++)
    {
        int temp=curr;
        curr=prev+curr;
        prev=temp;
    }
    return curr;
}
int fibonacchi(int x)
{
    vector<int> dp(x + 1, -1);
    return fib(x, dp);
}

int main()
{
    cout<<f(6);
}