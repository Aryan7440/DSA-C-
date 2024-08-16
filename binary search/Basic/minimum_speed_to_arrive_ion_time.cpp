#include <bits/stdc++.h>
using namespace std;
int minSpeedOnTime(vector<int> &dist, double hour)
{
    int n = dist.size();
    int l = 1, r = 10;
    int mid = l + (r - l) / 2;
    int ans = 0;
    while (l <= r)
    {
        mid = l + (r - l) / 2;

        double h = 0;
        for (int i = 0; i < n - 1; i++)
        {
            double t = (double)dist[i] / mid;
            h += ceil(t);
        }
        h += (double)dist[n - 1] / mid;
        if (h > hour)
            l = mid + 1;
        else
        {
            ans = mid;
            r = mid - 1;
        }
    }
    return ans == 10 ? -1 : ans;
}
int main()
{
    vector<int>dist={1,3,2};
    cout<<minSpeedOnTime(dist,1.9);
}