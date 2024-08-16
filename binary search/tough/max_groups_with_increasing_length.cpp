#include <bits/stdc++.h>
using namespace std;
bool help(vector<int> &usageLimits, int g)
{
    int prev = 0;
    for (auto i : usageLimits)
    {
        if (i != prev)
        {
            g--;
            prev = i;
        }
        if (g == 0)
            return true;
    }
    return false;
}
int maxIncreasingGroups(vector<int> &usageLimits)
{
    int l = 0, n = usageLimits.size(), r = n;
    sort(usageLimits.begin(), usageLimits.end());
    int mid = l + (r - l) / 2;
    int ans = 0;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (help(usageLimits, mid))
        {
            ans = l;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ans;
}
int main()
{
    vector<int> usageLimits={1,1};
    cout<<maxIncreasingGroups(usageLimits);
}