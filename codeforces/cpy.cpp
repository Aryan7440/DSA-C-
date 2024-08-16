#include <bits/stdc++.h>
using namespace std;
int util(vector<int> nums, int ind, int d)
{
    if (ind >= nums.size() - 1)
        return 1;
    int res = INT_MAX;
    for (int i = ind + 1; i <= ind + d + 1 && i < nums.size(); i++)
    {
        res = min(res, 1 + nums[ind] + util(nums, i, d));
    }
    return res;
}
int main()
{
    // vector<int> nums = {0, 3, 4, 8, 0};
    // vector<int> nums = {0, 1, 2, 3, 2, 1, 2, 3, 3, 2, 0};
    vector<int> nums = {0, 10, 4, 8, 4, 4, 2, 0};
    int d = 1;
    cout << util(nums, 0, d);
}