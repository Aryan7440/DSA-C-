#include <bits/stdc++.h>
using namespace std;
int reverse(int x)
{
    int ans=0;
    int l=0;
    while(x)
    {
        l=x%10;
        x=x/10;
        if(ans>INT_MAX/10 ||  (ans==INT_MAX/10 && l>7))return 0;
        ans=ans*10 +l;
    }

    return ans;
}

int main()
{
    cout<<INT_MIN;
}