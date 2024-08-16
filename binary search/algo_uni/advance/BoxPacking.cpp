#include <bits/stdc++.h>
using namespace std;

bool Predicate(long long w, long long h, long long a, long long N)
{
    long long H = a / h;
    long long W = a / w;
    long long totalBoxes = H * W;
    if (totalBoxes >= N)
        return 1;
    else
        return 0;
}
void solve()
{
    long long w, h, n;
    cin >> w >> h >> n;
    int l = 1, r = 1;
    while (Predicate(w, h, r, n) != 1)
        r = r * 2;

    while (l + 1 < r)
    {
        long long mid = l + (r - l) / 2;
        if (Predicate(w, h, mid, n) == 0)
            l = mid;
        else
            r = mid;
    }
    cout << r << endl;
}
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}