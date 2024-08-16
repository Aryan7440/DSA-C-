#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int> &temp)
{
    stack<int> st;
    int n = temp.size();
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && temp[i] >= temp[st.top()])
        {
            st.pop();
        }
        ans[i] = (st.empty()) ? 0 : st.top() - i;
        st.push(i);
    }
    return ans;
}
int main()
{
    vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = dailyTemperatures(temp);
    for (auto i : ans)
        cout << i << " ";
}