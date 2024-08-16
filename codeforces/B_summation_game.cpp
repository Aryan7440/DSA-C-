#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k, x;
        cin >> n >> k >> x;
        vector<long long> arr(n);
        vector<long long> pre(n, 0);
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
        {
            pre[i] = sum + arr[i];
            sum += arr[i];
        }
        long long ans = LONG_LONG_MIN;
        if (k >= n)
            ans = 0;

        for (int i = 0; i <= k; i++)
        {
            if (n - i - x >= 0)
            {
                if (n - i - 1 - x < 0)
                    continue;
                long long neg = pre[n - i - 1] - pre[n - i - x - 1];
                long long pos = pre[n - i - x - 1];
                ans = max(ans, pos - neg);
            }
            else
            {
                ans = max(ans, -pre[n - i - 1]);
            }
        }
        cout << ans << endl;
    }
}