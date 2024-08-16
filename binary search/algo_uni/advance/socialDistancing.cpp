#include <bits/stdc++.h>
using namespace std;
bool Predicate(int n, int m, vector<pair<long, long>> &islands, long long min_dist)
{
    int people = 1;
    long long prev = islands[0].first;
    int curr = 0;
    while (prev + min_dist <= islands[m - 1].second)
    {
        while (curr < m && prev + min_dist <= islands[curr].second)
        {
            people++;
            prev += min_dist;
        }
        while (curr < m && prev + min_dist > islands[curr].second)
            curr++;
        if (curr < m && prev + min_dist < islands[curr].first)
        {
            people++;
            prev = islands[curr].first;
        }
        else if (curr < m)
        {
            people++;
            prev = prev + min_dist;
        }
    }
    return people >= n;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<long, long>> islands(m);
    for (int i = 0; i < m; i++)
        cin >> islands[i].first >> islands[i].second;
    sort(islands.begin(), islands.end());
    long long l = 0, r = 1e18 + 1;
    // while (Predicate(n, m, islands, r) == 0)
    //     r = r * 2;
    while (l + 1 < r)
    {
        long long mid = l + (r - l) / 2;
        if (Predicate(n, m, islands, mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << endl;
    return 0;
}