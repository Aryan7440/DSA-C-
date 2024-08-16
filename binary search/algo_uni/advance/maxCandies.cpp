#include <bits/stdc++.h>
using namespace std;

bool Predicate(long long i, long long N)
{
    if ((i * (i + 1) / 2) <= N)
        return 0;
    return 1;
}
int main()
{

    // cout << "Hello World";
    long long n;
    cin >> n;
    long long l = 0, r = 1;
    while (Predicate(r, 1e18) != 1)
        r = r * 2;

    while (l + 1 < r)
    {
        long long mid = l + (r - l) / 2;
        if (Predicate(mid, n) == 0)
            l = mid;
        else
            r = mid;
    }
    cout << l << endl;
    // long long int discriminant = 1 + 8 * n;
    // long long int x=floor((-1+sqrt(discriminant))/2);
    // cout<<x<<'\n';

    return 0;
}