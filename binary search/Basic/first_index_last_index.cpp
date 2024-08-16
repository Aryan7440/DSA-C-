#include <bits/stdc++.h>
using namespace std;
int firstIndex(vector<int> &nums, int x)
{
    int l = 0, r = nums.size() - 1;
    int ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] < x)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ans + 1;
}
int LastIndex(vector<int> &nums, int x)
{
    int l = 0, r = nums.size() - 1;
    int ans = nums.size();
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] <= x)
            l = mid + 1;
        else
        {
            ans = mid;
            r = mid - 1;
        }
    }
    return ans - 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    for (int i = 0; i < q; i++)
    {
        int query;
        cin >> query;
        int lb = firstIndex(nums, query);
        int ub = LastIndex(nums, query);
        if (lb == n || ub < 0 || ub == n || lb < 0)
        {
            cout << -1 << " " << -1 << '\n';
            continue;
        }
        cout << lb << " " << ub << '\n';
    }
    return 0;
}