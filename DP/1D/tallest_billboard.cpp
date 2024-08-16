#include <bits/stdc++.h>
using namespace std;
int util(vector<int> &rods, int ind, int diff)
{
    if (ind == rods.size())
    {
        return (diff == 0) ? 0 : INT_MIN;
    }

    int left = rods[ind] + util(rods, ind + 1, diff + rods[ind]);
    int right = util(rods, ind + 1, diff - rods[ind]);
    int move = util(rods, ind + 1, diff);
    return max(left, max(right, move));
}
int tallestBillboard(vector<int> &rods)
{
    return util(rods, 0, 0);
}
int main()
{
    vector<int> rods={1,2};
    cout<<tallestBillboard(rods);
}