#include <bits/stdc++.h>
using namespace std;

int firstIndex(vector<int> &nums, int x)
{
    int n = nums.size();
    int l = -1, r = n;
    while (l + 1 < r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] < x)
            l = mid;
        else
            r = mid;
    }
    return r;
}
int LastIndex(vector<int> &nums, int x)
{
    int n = nums.size();
    int l = -1, r = n;
    while (l + 1 < r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] <= x)
            l = mid;
        else
            r = mid;
    }
    return l;
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
        if (lb >= 0 && nums[lb] == query && ub < n && nums[ub] == query)
        {
            cout << lb << " " << ub << '\n';
        }
        else
            cout << -1 << " " << -1 << '\n';
    }
    return 0;
}