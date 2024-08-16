#include <bits/stdc++.h>
using namespace std;

long long maxRunTime(int n, vector<int> &batteries)
{
    // int n=batteries.size();
    long long l = 0, r = accumulate(batteries.begin(), batteries.end(), 0) / n;
    long long mid = l + (r - l) / 2;
    long long ans = 0;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        long long tt = 0;
        for (auto t : batteries)
        {
            if (t > mid)
                tt += mid;
            else
                tt += t;
        }
        long long calT = n * mid;
        if (tt >= calT)
        {
            ans=mid;
            l = mid+1;
        }
        else
            r = mid - 1;
    }
    return ans;
}
int main()
{
    vector<int> batteries = {3, 3, 3};
    cout << maxRunTime(2, batteries);
}