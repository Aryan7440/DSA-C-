#include <bits/stdc++.h>
using namespace std;
vector<int> dd = {1, 7, 30};
int util(vector<int> &days, vector<int> &costs, int ind)
{
    if (ind >= days.size())
        return 0;
    int res = 1e9;
    for (int i = 0; i < 3; i++)
    {
        int day = days[ind];
        int in = dd[i];
        int k = ind;
        while (days[k] <= day + in)
            k++;
        res = min(res, costs[i] + util(days, costs, k));
    }
    return res;
}
int mincostTickets(vector<int> &days, vector<int> &costs)
{
    return util(days, costs, 0);
}
int main()
{
    vector<int> days = {1,4,6,7,8,20}, costs = {2,7,15};
    cout<<mincostTickets(days,costs);
}