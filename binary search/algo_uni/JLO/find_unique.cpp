#include <bits/stdc++.h>
using namespace std;
bool P(vector<int> &nums, int mid)
{
    int n = nums.size();
    if (mid == n - 1)
        return true;
    if (mid % 2 == 0 && nums[mid] != nums[mid + 1])
        return true;
    else if (mid % 2 != 0 && nums[mid] == nums[mid + 1])
        return true;
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        int l = -1, r = n - 1;
        while (l + 1 < r)
        {
            int mid = l + (r - l) / 2;
            if (P(nums, mid))
                r = mid;
            else
                l = mid;
        }
        cout << nums[r] << endl;
    }

    return 0;
}