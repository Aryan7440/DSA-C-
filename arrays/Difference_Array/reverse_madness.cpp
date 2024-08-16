#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> l(k), r(k);
    for (int i = 0; i < k; i++)
        cin >> l[i];
    for (int i = 0; i < k; i++)
        cin >> r[i];
    int q;
    cin >> q;
    vector<int> que(q);
    for (int i = 0; i < q; i++)
        cin >> que[i];
    vector<int> range(n + 1, -1);
    for (int i = 0; i < k; i++)
    {
        for (int j = l[i]; j <= r[i]; j++)
            range[j] = i;
    }

    vector<int> diff(n + 1, 0);
    for (int i = 0; i < q; i++)
    {
        int qi = que[i];
        int L = l[range[qi]];
        int R = r[range[qi]];

        int a = min(qi, L + R - qi);
        int b = max(qi, L + R - qi);

        diff[a - 1] += 1;
        diff[b] -= 1;
    }
    // vector<int> prefix(n+1,0);
    for (int i = 1; i <= n; i++)
        diff[i] = diff[i - 1] + diff[i];
    for (int i = 0; i < n; i++)
    {
        if (diff[i] % 2 != 0)
        {
            int L = l[range[i + 1]] - 1;
            int R = r[range[i + 1]] - 1;
            int ind = L + R - i;
            if (ind < i)
                continue;
            swap(s[i], s[ind]);
        }
    }
    cout << s << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}