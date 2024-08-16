#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
    long cn = n;
    if (cn < 0)
        cn = (-1) * cn;
    double ans = 1;
    while (cn > 0)
    {
        if (cn % 2 != 0)
        {
            cn = cn - 1;
            ans = ans * x;
        }
        else
        {
            cn = cn / 2;
            x = x * x;
        }
    }
    if (n > 0)
        return ans;
    else
        return 1 / ans;
}

double Pow(double x, int n)
{
    if (n == 0)
        return 1.0;
    if (n > 0)
    {
        double temp = Pow(x, n / 2);
        if (n % 2 == 0)
            return temp * temp;
        else
            return temp * temp * x;
    }
    else
    {
        return (1 / x) * Pow(1 / x, -(n + 1));
    }
}
long long mod = 1e9 + 7;
long long power(long long n, long long x)
{
    if (x == 0)
        return 1;
    if (n & 1 != 0)
    {
        return n * (power(n * n, x >> 2) % mod) % mod;
    }
    else
    {
        return (power(n * n, x >> 2) % mod);
    }
}

