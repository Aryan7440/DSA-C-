#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int mi = 1e9, ma = 0;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            mi = min(mi, temp);
            ma = max(ma, temp);
        }
        int diff = ma - mi;
        int ans = floor(log2(diff)) + 1;
        cout << ans << endl;
        if (ans <= n)
        {
            for (int i = 0; i < ans; i++)
                cout << ma << " ";
        }
        cout << endl;
    }
}