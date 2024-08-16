#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void perm(vector<int> arr,vector<int> &ds,vector<bool>&mp,vector<vector<int>> &ans)
{
    if(ds.size()==arr.size())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if(mp[i])continue;
        if(i>0 && arr[i]==arr[i-1] && !mp[i-1])continue;

        mp[i]=true;
        ds.push_back(arr[i]);
        perm(arr,ds,mp,ans);
        ds.pop_back();
        mp[i]=false;
    }
    
}

vector<vector<int>> permutation1(vector<int> &arr)  //wont work on array with non-distinct values
{
    vector<vector<int>> ans;
    vector<int> ds;
    vector<bool> mp(arr.size(),false);
    sort(arr.begin(),arr.end());
    perm(arr,ds,mp,ans);
    return ans;
}

int main()
{
    vector<int> arr = {1, 1,1};
    // sort(arr.begin(),arr.end());
    vector<vector<int>> ans=permutation1(arr);
    display(ans);
}