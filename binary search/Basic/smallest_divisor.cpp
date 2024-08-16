#include <bits/stdc++.h>
using namespace std;
static bool check(vector<int> &nums, int threshold, int mid)
{
    int sum = 0;
    for (auto i : nums)
    {
        (i % mid == 0) ? sum += (i / mid) : sum += (i / mid) + 1;
        if (sum > threshold)
            return false;
    }
    return true;
}
int smallestDivisor(vector<int> &nums, int threshold)
{
    int l = 1, r = 0;
    for (auto i : nums)
        r = max(r, i);
    int mid = l + (r - l) / 2;
    while (l <= r)
    {
        mid=l+(r-l)/2;
        if (check(nums, threshold, mid))
        {
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    vector<int> nums={1,2,5,9};
    cout<<smallestDivisor(nums,6);
}