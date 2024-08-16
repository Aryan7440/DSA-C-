#include <bits/stdc++.h> 
using namespace std;
int mod=1e9+7;
#define ll long long
int util(string exp,int i,int j,bool isTrue,vector<vector<vector<int>>>&dp)
{
    if(i>j)return 0;
    if(i==j)
    {
        if(isTrue)return (exp[i]=='T')?1:0;
        else return (exp[i]=='F')?1:0;
    }
    if(dp[i][j][isTrue]!=-1)return dp[i][j][isTrue];
    int ans=0;
    for(int k=i;k<=j;k++)
    {
        if(exp[k]!='F' && exp[k]!='T')
        {
            int t1=util(exp,i,k-1,1,dp);
            int t2=util(exp,k+1,j,1,dp);
            int f1=util(exp,i,k-1,0,dp);
            int f2=util(exp,k+1,j,0,dp);
            if(exp[k]=='|')
            {
                if(isTrue)ans+=((t1*t2)%mod+(t1*f2)%mod+(t2*f1)%mod)%mod;
                else ans+=(f1*f2)%mod;
            }
            else if(exp[k]=='&')
            {
                if(isTrue)ans+=(t1*t2)%mod;
                else ans+=((f1*f2)%mod+(f1*t2)%mod+(f2*t1)%mod)%mod;
            }
            else
            {
                if(isTrue)ans+=((t1*f2)%mod +(t2*f1)%mod)%mod;
                else ans+=((t1*t2)%mod+(f1*f2)%mod)%mod;
            }
        }
    }
    return dp[i][j][isTrue]=ans%mod;
}
int evaluateExp(string & exp) {
    // Write your code here.
    int n=exp.size();
    vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(n,vector<ll>(2,0)));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<n;j++)
        {
            for(int isTrue=0;isTrue<=1;isTrue++)
            {
                if(i>j)continue;
                if (i == j) 
                {
                    dp[i][j][1] = (exp[i] == 'T') ;
                    dp[i][j][0] = (exp[i] == 'F') ;
                }
                else
                {
                    long long int ans=0;
                    for(int k=i;k<=j;k++)
                    {
                        if(exp[k]!='F' && exp[k]!='T')
                        {
                            ll t1=dp[i][k-1][1];
                            ll t2=dp[k+1][j][1];
                            ll f1=dp[i][k-1][0];
                            ll f2=dp[k+1][j][0];
                            if(exp[k]=='|')
                            {
                                if(isTrue)ans+=((t1*t2)%mod+(t1*f2)%mod+(t2*f1)%mod)%mod;
                                else ans+=(f1*f2)%mod;
                            }
                            else if(exp[k]=='&')
                            {
                                if(isTrue)ans+=(t1*t2)%mod;
                                else ans+=((f1*f2)%mod+(f1*t2)%mod+(f2*t1)%mod)%mod;
                            } else {
                            if (isTrue)
                                ans += ((t1 * f2) % mod + (t2 * f1) % mod) % mod;
                            else
                                ans += ((t1 * t2) % mod + (f1 * f2) % mod) % mod;
                            }
                        }
                    }
                    dp[i][j][isTrue] = ans % mod;
                }
            }
        }
        
    }
    return dp[0][n-1][1];
}
int main()
{
    string exp="T&T^F^F";
    cout<<evaluateExp(exp);
}