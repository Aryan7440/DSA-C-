#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> &nums, int k, int mid)
{
    int count = 1;
    int sum = 0;
    for (auto i : nums)
    {
        sum += i;
        if (sum > mid)
        {
            sum = i;
            count++;
            if (count > k)
                return true;
        }
    }
    return false;
}

int splitArray(vector<int> &nums, int k)
{
    int l = 0, r = 0;
    for (auto i : nums)
    {
        l=max(l,i);
        r += i;
    }
    int mid = l + (r - l) / 2;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (check(nums, k, mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

int main()
{
    vector<int> nums = {1, 4, 4};
    cout << splitArray(nums, 3);
}