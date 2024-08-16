
#include <bits/stdc++.h>
using namespace std;
bool Predicate(vector<long long> &nums, long long x, long long k)
{
    // predicate function
    int count = 0;
    int subArrays = 0;
    for (int i = 0; i < nums.size() && nums[i] <= x; i++)
    {
        if ((nums[i] | x) <= x)
        {
            count++;
            subArrays = subArrays + count;
        }
    }
    // int subArrays=pow(2,)

    return subArrays >= k;
}
void solve()
{
    long long n, x;
    cin >> n >> x;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums.begin(), nums.end());
    long long l = 0, r = 1;
    r = 1;
    while (Predicate(nums, r, x) == 0)
        r = r * 2;
    double d = 1;
    while (l + d < r)
    {
        long long mid = l + (r - l) / 2;
        if (Predicate(nums, mid, x))
            r = mid;
        else
            l = mid;
    }
    // cout << l << "\n";
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