#include <bits/stdc++.h>
using namespace std;

// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

void combi(int k, int n, vector<vector<int>> &ans, vector<int> &ds, int sum, int i,int numb=1)
{
    if (i == k)
    {
        if (sum == n)
            ans.push_back(ds);
        return;
    }
    if(numb>9)return;

    ds.push_back(numb);
    // sum+=numb;
    combi(k,n,ans,ds,sum+numb,i+1,numb+1);
    ds.pop_back();
    // sum-=numb;
    combi(k,n,ans,ds,sum,i,numb+1);
}

vector<vector<int>> combIII(int n,int k)
{
    vector<vector<int>> ans;
    vector<int> ds;
    combi(k,n,ans,ds,0,0,1);
    return ans;
}

int main()
{
    vector<vector<int>> ans=combIII(9,3);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
}