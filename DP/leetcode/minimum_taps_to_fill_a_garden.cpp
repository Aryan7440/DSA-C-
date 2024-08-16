#include <bits/stdc++.h>
using namespace std;
int util(int n, vector<pair<int, int>> &range, int ind)
{
    if (range[ind].second >= n)
        return 1;
    int res = 1e6;
    int i = ind + 1;
    while (i < n + 1 && range[i].first <= range[ind].second)
    {
        res = min(res, 1 + util(n, range, i));
        i++;
    }
    return res;
}
int minTaps(int n, vector<int> &ranges)
{
    vector<pair<int, int>> range;
    for (int i = 0; i < n + 1; i++)
    {
        range.push_back({max(0,i - ranges[i]), i + ranges[i]});
    }
    sort(range.begin(), range.end());
    int ans = 1e6;
    for(int i=0;i<n+1;i++)
    {
        if(range[i].first==0)ans=min(ans,util(n, range, i));
    }
    
    if (ans == 1e6)
        return -1;
    return ans;
}
int main()
{
    vector<int> ranges={2,1,2,1,2,4,3,0,1,0,5,2};
    cout<<minTaps(11,ranges);

}