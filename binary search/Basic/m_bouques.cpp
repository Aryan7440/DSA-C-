#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &bloomDay, int m, int k, int d)
{
    // sliding window
    int i = 0;
    int j = 0;
    int bouques = 0, flowers = 0;
    while (j < bloomDay.size())
    {
        while ( j<bloomDay.size() && j - i + 1 <= k)
        {
            if (bloomDay[j] <= d)
                flowers++;
            if (flowers == k)
            {
                bouques++;
                i=j+1;
                flowers=0;
            }
            if (bouques == m)
                return true;
            j++;
        }
        if (i<bloomDay.size() && j - i + 1 > k)
        {
            if (bloomDay[i] <= d)
                flowers--;
            i++;
        }
    }
    return false;
}
int minDays(vector<int> &bloomDay, int m, int k)
{
    int l = 1;
    int r = 0;
    for (auto i : bloomDay)
        r = max(i, r);
    int mid = l + (r - l) / 2;
    int days = INT_MAX;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (check(bloomDay, m, k, mid))
        {
            r = mid - 1;
            days = min(days, mid);
        }
        else
            l = mid + 1;
    }
    return days == INT_MAX ? -1 : days;
}
int main()
{
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 2;
    cout << minDays(bloomDay, m, k);
}