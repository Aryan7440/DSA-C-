#include <bits/stdc++.h>
using namespace std;

static bool check(vector<int> &weights, int days, int w)
{
    int day = 0;
    int count = 1;
    for (auto i : weights)
    {
        day += i;
        if (day > w)
        {
            day = i;
            count++;
            if (count > days)
                return false;
        }
    }
    return true;
}
int shipWithinDays(vector<int> &weights, int days)
{
    int l = 1, r = 0;
    for (auto i : weights)
    {
        r = r + i;
    }
    int mid = l + (r - l) / 2;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (check(weights, days, mid))
        {
            r = mid-1;
        }
        else
            l = mid + 1;
    }
    return l;
}
int main()
{
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << shipWithinDays(weights, 5);
}