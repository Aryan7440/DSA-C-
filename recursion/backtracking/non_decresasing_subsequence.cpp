#include <bits/stdc++.h>
using namespace std;
void subs(vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds, int ind, set<vector<int>> &s)
{
    if (ind == nums.size())
    {
        if (ds.size() >= 2 && s.find(ds) == s.end())
        {
            s.insert(ds);
            ans.push_back(ds);
        }
        return;
    }
    if (ds.size() == 0 || nums[ind] >= ds.back())
    {
        ds.push_back(nums[ind]);
        subs(nums, ans, ds, ind + 1, s);
        ds.pop_back();
    }
    subs(nums, ans, ds, ind + 1, s);
}
vector<vector<int>> findSubsequences(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    set<vector<int>> s;
    subs(nums, ans, ds, 0, s);
    return ans;
}
int main()
{
    vector<int> nums = {4, 6, 7, 7};
    vector<vector<int>> ans = findSubsequences(nums);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}