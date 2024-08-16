#include <bits/stdc++.h>
using namespace std;
int maximalNetworkRank(int n, vector<vector<int>> &roads)
{
    vector<int> mp(n, 0);
    for (auto i : roads)
    {
        mp[i[0]]++;
        mp[i[1]]++;
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int k = i+1; k < n; k++)
        {
            int l = i, r = k;
            int join = 0;
            for (int j = 0; j < roads.size(); j++)
            {
                if ((roads[j][0] == l && roads[j][1] == r) || (roads[j][0] == r && roads[j][1] == l))
                {
                    join = 1;
                }
            }
            if (join)
                ans = max(ans, mp[l] + mp[r] - 1);
            else
                ans = max(ans, mp[l] + mp[r]);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> roads = {{0, 1}, {1, 2}, {2, 3}, {2, 4}, {5, 6}, {5, 7}};
    cout << maximalNetworkRank(8, roads);
}