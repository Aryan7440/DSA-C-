#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n - 1; i++)
    {
        pq.push({abs(a[i + 1] - a[i]), i});
    }
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    while (k-- && !pq.empty())
    {
        auto [d, i] = pq.top();
        if (d != abs(a[i] - a[i + 1]))
        {
            pq.pop();
            continue;
        }
        pq.pop();
        a[i] = min(a[i], a[i + 1]);
        a[i + 1] = min(a[i], a[i + 1]);
        sum -= d;
        pq.push({abs(a[i] - a[i + 1]), i});
        if (i - 1 >= 0)
        {
            pq.push({abs(a[i] - a[i - 1]), i - 1});
        }
    }
    cout << sum << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
