int mod = 1e9 + 7;
int fact[100002];
int MOD_MUL(int a, int b)
{
    return ((long long)(a % mod) * (long long)(b % mod)) % mod;
}
int MOD_ADD(int a, int b)
{
    return ((long long)(a % mod) + (long long)(b % mod)) % mod;
}
int MOD_SUB(int a, int b)
{
    return ((long long)(a % mod) + (long long)(b % mod)) % mod;
}
int MOD_DIV(int a, int b)
{
    return MOD_MUL(a, MULI(b));
}
int BinExpo(int a, int m)
{
    if (m == 0)
        return 1;
    int res = BinExpo(a, m / 2);
    res = MOD_MUL(res, res);
    return (m % 2 == 0) ? res : MOD_MUL(res, a);
}
int MULI(int a)
{
    return BinExpo(a, mod - 2);
}
void factorial()
{
    fact[0] = 1;
    for (int i = 1; i < 100001; i++)
        fact[i] = MOD_MUL(fact[i - 1], i);
}
int nCr(int n, int r)
{
    return MOD_MUL(fact[n], MULI(MOD_MUL(fact[r], fact[n - r])));
}
int gcd(int x, int y)
{
    if (x < y)
        return gcd(y, x);
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
