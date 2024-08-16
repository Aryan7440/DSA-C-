#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    // cin >> n;
    n = 6;
    // vector<int> nums(n);
    vector<int> nums = {-1, -2, -3, -4, -5, -6};
    // for (int i = 0; i < n; i++)
    //     cin >> nums[i];
    vector<int> dpl(n), dpr(n);
    dpl[0] = nums[0];
    int res = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        dpl[i] = max(nums[i], dpl[i - 1] + nums[i]);
        res = max(res, dpl[i]);
    }
    dpr[n - 1] = nums[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        dpr[i] = max(nums[i], dpr[i + 1] + nums[i]);
        res = max(res, dpr[i]);
    }

    for (int i = 1; i < n - 1; i++)
    {
        res = max(res, dpl[i - 1] + dpr[i + 1]);
    }
    cout << res << endl;

    return 0;
}
