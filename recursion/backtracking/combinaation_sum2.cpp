#include<bits/stdc++.h>
using namespace std;

void comb(vector<int> &arr,int ind,int target,vector<int> &ds,vector<vector<int>>& ans)
{
    if(target==0)
    {
        ans.push_back(ds);
        return;
    }
    for (int i = ind; i < arr.size(); i++)
    {
        if(i>ind && arr[i]==arr[i-1])continue;
        if(arr[i]>target)break;
        ds.push_back(arr[i]);
        comb(arr,ind+1,target-arr[i],ds,ans);
        ds.pop_back();
    }
}

vector<vector<int>> combination_sum2(vector<int> arr,int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(),arr.end());
    comb(arr,0,target,ds,ans);
    return ans;
}
int main()
{
    vector<int> arr={1,2,2,2,3,3,3};
    vector<vector<int>> ans=combination_sum2(arr,7);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
}