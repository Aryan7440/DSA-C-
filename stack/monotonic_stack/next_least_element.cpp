#include <bits/stdc++.h>
using namespace std;
vector<int> next_least_element(vector<int> nums)
{
    int n = nums.size();
    stack<pair<int, int>> st;
    vector<int> nsi(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int h = nums[i];
        if (st.empty())
        {
            nsi[i] = n;
        }
        else
        {
            while (!st.empty() && st.top().first > h)
            {
                st.pop();
            }
            if (st.empty())
            {
                nsi[i] = n;
            }
            else
            {
                nsi[i] = st.top().second;
            }
        }
        st.push({h, i});
        
    }
    return nsi;
}
int main()
{
    vector<int> nums={2,1,5,6,2,3};
    vector<int> ans=next_least_element(nums);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
}