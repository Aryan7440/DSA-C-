#include <bits/stdc++.h>
using namespace std;
int util(vector<int> &profit, vector<int> &size, vector<int> &cap, int ind, int s, vector<vector<int>> &dp)
{
    if (ind == profit.size())
    {
        return 0;
    }
    if (s > cap[ind])
    {
        return -1e9;
    }
    int take = 0;
    if (s + size[ind] <= cap[ind])
    {
        take = profit[ind] + util(profit, size, cap, ind + 1, s + size[ind], dp);
    }
    int not_take = util(profit, size, cap, ind + 1, s, dp);
    return max(take, not_take);
}
int main()
{
    vector<int> profit = {10, 100, 30, 50, 25};
    vector<int> size = {1, 10, 4, 7, 3};
    vector<int> cap = {10, 12, 8, 13, 17};
    vector<vector<int>> dp(profit.size() + 1, vector<int>(18, -1));
    cout << util(profit, size, cap, 0, 0, dp) << endl;
    return 0;
}