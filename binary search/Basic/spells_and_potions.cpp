#include <bits/stdc++.h>
using namespace std;
int binary_search(int x, vector<int> &potions, long long success)
{
    int l = 0, r = potions.size() - 1;
    int mid = l + (r - l) / 2;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (x * potions[mid] >= success)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return r;
}
vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
    sort(potions.begin(), potions.end());
    vector<int> ans;
    for (int i = 0; i < spells.size(); i++)
    {
        int res = potions.size() - 1 - binary_search(spells[i], potions, success);
        ans.push_back(res);
    }
    return ans;
}
int main()
{
    vector<int>spells={3,1,2},potions={8,5,8};
    long long int success=16;
    vector<int>ans=successfulPairs(spells,potions,success);
    for(auto i:ans)cout<<i<<" ";
}