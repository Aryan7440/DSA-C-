#include <bits/stdc++.h>
#include "DS.h"
using namespace std;
bool canTraverseAllPairs(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    unordered_set<int> st(nums.begin(), nums.end());
    disjoint_set ds(1e5 + 1);
    for (int i = 0; i < nums.size(); i++)
    {
        int n = nums[i];
        int sq = sqrt(n);
        for (int fac = 1; fac <= sq; fac++)
        {
            int fac1=n/fac;
            if (n % fac == 0 && st.find(fac) != st.end())
            {
                ds.union_bysize(n, fac);
            }
            if (n % fac1 == 0 && st.find(fac1) != st.end())
            {
                ds.union_bysize(n, fac1);
            }
        }
    }
    for (int i = 1; i < nums.size(); i++)
    {
        if (ds.find_parent(nums[0]) != ds.find_parent(nums[i]))
            return false;
    }
    return true;
}
int main()
{
    // vector<int> nums = {3, 9, 5};
    vector<int> nums = {4, 3, 12, 8};
    // vector<int> nums = {2, 3, 6};
    cout << canTraverseAllPairs(nums);
}