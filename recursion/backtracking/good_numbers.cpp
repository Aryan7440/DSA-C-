#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;

long long power(int n, int x)
{
    if (x == 0)
        return 1;
    if (x % 2 == 0)
    {
        return power((n * n) % mod, x / 2);
    }
    else
    {
        return n * (power((n * n) % mod, x / 2)) % mod;
    }
}
int countGoodNumbers(long long n)
{
    if (n % 2 == 0)
    {
        return ((power(5, n / 2) % mod) * (power(4, n / 2) % mod)) % mod;
    }
    else
    {
        return 5 * ((power(5, n / 2) % mod) * (power(4, n / 2) % mod)) % mod;
    }
}

int main()
{
    cout<<countGoodNumbers(50);
}