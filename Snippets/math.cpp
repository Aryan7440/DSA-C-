#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int fact[100002];
int MUL(int a, int b)
{
    return ((long long)(a % mod) * (long long)(b % mod)) % mod;
}
int BinExpo(int a, int m)
{
    if (m == 0)
        return 1;
    int res = BinExpo(a, m / 2);
    res = MUL(res, res);
    return (m % 2 == 0) ? res : MUL(res, a);
}
int MULI(int a)
{
    return BinExpo(a, mod - 2);
}
void factorial()
{
    fact[0] = 1;
    for (int i = 1; i < 100001; i++)
        fact[i] = MUL(fact[i - 1], i);
}