#include <bits/stdc++.h>
using namespace std;
void sub_sets(vector<int> &nums, int ind, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);
    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        sub_sets(nums, i + 1, ds, ans);
        ds.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    sub_sets(nums, 0, ds, ans);
    return ans;
}
int main()
{
    vector<int> nums={1,2,2};
    auto ans=subsetsWithDup(nums);
    for(auto i:ans)
    {
        for(auto j:i)cout<<j<<" ";
        cout<<endl;
    }
}