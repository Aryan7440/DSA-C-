#include <bits/stdc++.h>
using namespace std;

long long at(long long X, long long i)
{
    return ((1 << i) & X);
}
long long findPairY(long long X)
{
    // Write your code here.
    bitset<64> a = X;
    long long l = 62;
    // a = 1 << 43;
    while (l >= 0 && ((1 << l) & X) == 0)
        l--;

    long long r = 0;
    long long res = 0;
    while (l >= r)
    {
        if (at(X, l) || at(X, r))
            res = res | (1 << l) | (1 << r);
        l--;
        r++;
    }

    return X ^ res;
}

int main()
{
    cout << findPairY(8);
}