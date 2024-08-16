#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> mp;
    stack<int> st;
    int n = nums2.size();
    int m = nums1.size();
    for (int i = n - 1; i >= 0; i--)
    {
        int num = nums2[i];
        if (st.empty())
        {
            mp[num] = -1;
            st.push(num);
        }
        else
        {
            while (!st.empty() && st.top() < nums2[i])
            {
                st.pop();
            }
            
            if (!st.empty())
            {
                mp[num] = st.top();
            }
            else
                mp[num] = -1;
            st.push(num);
        }
    }
    vector<int> ans;
    for (auto i : nums1)
    {
        ans.push_back(mp[i]);
    }
    return ans;
}
int main()
{
    vector<int> nums1={2,1,3},nums2={2,3,1};
    // vector<int> nums1={4,1,2},nums2={1,3,4,2};
    vector<int> ans=nextGreaterElement(nums1,nums2);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
}