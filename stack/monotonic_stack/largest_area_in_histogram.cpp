#include <bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<pair<int, int>> st;
    vector<int> nsi(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int h = heights[i];
        if (st.empty())
        {
            nsi[i] = n;
        }
        else
        {
            while (!st.empty() && st.top().first >= h)
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
    while (!st.empty())
        st.pop();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int h = heights[i];
        if (st.empty())
        {
            // pli[i] = -1;
            ans = max(ans, (nsi[i] - (-1) - 1) * h);
        }
        else
        {
            while (!st.empty() && st.top().first > h)
            {
                st.pop();
            }
            if (st.empty())
            {
                // pli[i] = -1;
                ans = max(ans, (nsi[i] - (-1) - 1) * h);
            }
            else
            {
                // pli[i] = st.top().second;
                ans = max(ans, (nsi[i] - (st.top().second) - 1) * h);
            }
        }
        st.push({h, i});
    }
    return ans;
}
int max_area_histogram(vector<int> &heights) // one pass most optimal
{
    stack<int> st;
    int n = heights.size();
    int area = 0;
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() &&( i==n || heights[st.top()] >=heights[i]))
        {
            int h = heights[st.top()];
            st.pop();
            int r = i;
            int l = (st.empty()) ? -1 : st.top();
            area = max(area, h * (r - l-1));
        }
        st.push(i);
    }
    return area;
}
int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << max_area_histogram(heights);
    // cout << largestRectangleArea(heights);
}