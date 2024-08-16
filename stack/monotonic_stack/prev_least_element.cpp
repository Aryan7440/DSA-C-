#include<bits/stdc++.h>
using namespace std;
vector<int> previous_least_element(vector<int> &nums)
{
    int n = nums.size();
    stack<pair<int, int>> st;
    vector<int> pli(n);
    for (int i = 0;i<n;i++)
    {
        int h = nums[i];
        if (st.empty())
        {
            pli[i] = -1;
        }
        else
        {
            while (!st.empty() && st.top().first > h)
            {
                st.pop();
            }
            if (st.empty())
            {
                pli[i] = -1;
            }
            else
            {
                pli[i] = st.top().second;
            }
        }
        st.push({h, i});
    }
    return pli;
}
int main()
{
    vector<int> nums={2,1,5,6,2,3};
    vector<int> ans=previous_least_element(nums);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
}
//-1 -1 1 2 1 4   p 
// 1  6 4 4 6 6  n