#include <bits/stdc++.h>
using namespace std;
bool primeFactors(int n)
{
    int tc=0;
    while (n % 2 == 0)
    {
        n = n / 2;
        tc++;
    }
    if(tc>1)return false;
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        int nc=0;
        while (n % i == 0)
        {
            n = n / i;
            nc++;
            if(nc>1)return false;
        }
    }
    // if (n > 2)
        // cout << n << " ";
        return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans=n;
        int A=n;
        int P=1;
        while(primeFactors(n))
        {
            n=sqrt(n);
            A=n;
            P=
        }
    }
}