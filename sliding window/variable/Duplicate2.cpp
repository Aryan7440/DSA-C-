#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
bool checkDuplicate(vector<int> &arr, int n, int k) {
    int j=0;
    unordered_map<int,int>mp;
    while(j<n)
    {
        if(mp.find(arr[j])==mp.end())
        {
            mp[arr[j]]=j;
            j++;
        }
        else
        {
            if(j-mp[arr[j]]<=k)return true;
            else
            {
                mp[arr[j]]=j;
                 j++;
            }
        }
    }
    return false;
}
int main()
{
    vector<int> arr={1,2,3,4,7,5,3};
    cout<<checkDuplicate(arr,arr.size(),3);
}
