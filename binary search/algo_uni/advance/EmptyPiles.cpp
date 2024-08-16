#include <bits/stdc++.h>
using namespace std;
bool Predicate(vector<long long> &piles, long long k, long long h)
{
    long long op = 0;
    for (auto i : piles)
    {
        op += i / k + (i % k != 0);
    }
    return op <= h;
}
int main()
{
    long long n, h;
    cin >> n >> h;
    vector<long long> piles(n);
    for (int i = 0; i < n; i++)
        cin >> piles[i];
    long long l = 1, r = 1;
    while (Predicate(piles, r, h) == 0)
        r = r * 2;
    while (l + 1 < r)
    {
        long long mid = l + (r - l) / 2;
        if (Predicate(piles, mid, h))
            r = mid;
        else
            l = mid;
    }
    cout << r << endl;

    return 0;
}