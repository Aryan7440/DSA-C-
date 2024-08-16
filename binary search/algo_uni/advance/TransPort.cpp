#include <bits/stdc++.h>
using namespace std;
bool Predicate(long long n, long long m, long long c, vector<long long> &pass, long long mwt)
{
    long long prev = pass[0];
    long long count = 0;
    long long pass_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (pass[i] - prev > mwt || pass_count == c)
        {
            count++;
            prev = pass[i];
            pass_count = 1;
        }
        else
            pass_count++;
    }
    if (pass_count)
        count++;
    if (count <= m)
        return 1;
    else
        return 0;
}
int main()
{

    long long n, m, c;

    cin >> n >> m >> c;
    vector<long long> pass(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pass[i];
    }
    sort(pass.begin(), pass.end());

    long long l = 0, r = 1e9 + 1;
    while (l + 1 < r)
    {
        long long mid = l + (r - l) / 2;
        if (Predicate(n, m, c, pass, mid))
            r = mid;
        else
            l = mid;
    }

    cout << r << endl;

    return 0;
}