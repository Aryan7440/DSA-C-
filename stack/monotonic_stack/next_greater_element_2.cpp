#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(2 * n);
    stack<int> st;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        int num = nums[i % n];
        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            while (!st.empty() && st.top() <= num)
            {
                st.pop();
            }
            if (st.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = st.top();
            }
        }
        st.push(num);
    }
    while (ans.size() != n)
        ans.pop_back();
    return ans;
}
int main()
{
    vector<int>nums={1,2,3,4,3};
    vector<int> ans=nextGreaterElements(nums);
    for(auto i:ans)cout<<i <<" ";
}