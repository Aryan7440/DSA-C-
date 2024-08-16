#include <bits/stdc++.h>

using namespace std;
int minFlipsMonoIncr(string s)
{
    int n = s.size();
    int l = 0;
    int r = n - 1;
    int lc = 0;
    int rc = 0;
    int f1=0,f2=0;
    
    while (l < n && r >= 0)
    {
        if(s[l]=='1')f1=1;
        if(s[r]=='0')f2=1;
        if(s[l]=='0' && f1)lc++;
        if(s[r]=='1' && f2)rc++;
        l++;
        r--;
    }
    return min(lc, rc);
}

int main()
{
    string s="10011111110010111011";
    cout<<minFlipsMonoIncr(s);
}