#include <bits/stdc++.h>
using namespace std;
vector<int> smallestSubarrayWithKDistinct(vector<int> &arr, int k)
{
    vector<int> ans;
    if(k>arr.size())
    {
        ans.push_back(-1);
        return ans;
    }
    int i=0,j=0;
    int count=INT_MAX;
    unordered_map <int,int> mp;
    while(j<arr.size())
    {
        mp[arr[j]]++;
        if(mp.size()==k)
        {
            while(mp.size()==k)
            {
                if(count>j-i+1)
                {
                    count=j-i+1;
                    ans.clear();
                    ans.push_back(i);
                    ans.push_back(j);
                }
                mp[arr[i]]--;
                if(mp[arr[i]]==0)mp.erase(arr[i]);
                i++;
            }
        }
        j++;
    }
    if(ans.empty())
    {
        ans.push_back(-1);
    }
    return ans;
}
int main()
{
    vector<int> arr={1 ,2, 1, 2, 3};
    vector<int> ans=smallestSubarrayWithKDistinct(arr,3);
    for (int i = 0; i < 2; i++)
    {
        cout<<ans[i]<<" ";
    }
    
}
