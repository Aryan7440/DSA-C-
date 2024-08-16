#include <bits/stdc++.h>
using namespace std;

void combination_sum(vector<int> arr, int target, int n, vector<int> &ds, vector<vector<int>> &ans)
{
    if (n == arr.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }
    if (target >= arr[n])
    {
        ds.push_back(arr[n]);
        combination_sum(arr, target - arr[n], n, ds, ans);
        ds.pop_back();
    }
    combination_sum(arr, target, n + 1, ds, ans);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    combination_sum(candidates, target, 0, ds, ans);
    return ans;
}

int main()
{
    vector<int> arr={2,3,6,7,1};
    vector<vector<int>> ans;
    ans=combinationSum(arr,7);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
