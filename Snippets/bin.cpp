
#include <bits/stdc++.h>
using namespace std;
bool Predicate(vector<long long> &nums, long long x, long long k)
{
    // predicate function
    return true;
}
void solve()
{
    long long n, k;

    cin >> n >> k;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    long long l = 0, r = INT_MAX;
    r = 1;
    while (Predicate(nums, r, k) == 0)
        r = r * 2;
    double d = 1;
    while (l + d < r)
    {
        long long mid = l + (r - l) / 2;
        if (Predicate(nums, mid, k))
            r = mid;
        else
            l = mid;
    }
    cout << l << "\n";
    cout << r << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}