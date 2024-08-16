#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> maxHeights = {6, 5, 3, 4, 6, 1, 2, 3, 2, 5};
    int n = maxHeights.size();
    vector<pair<int, int>> st;
    long long stack_sum = 0;
    vector<long long> left(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (st.empty() || maxHeights[i] >= st.back().first)
        {
            stack_sum += maxHeights[i];
            st.push_back({maxHeights[i], i});
        }
        else
        {
            while (!st.empty() && maxHeights[i] < st.back().first)
            {
                pair<int, int> back = st.back();
                st.pop_back();
                if (!st.empty())
                    stack_sum -= (back.second - st.back().second) * back.first;
                else
                    stack_sum -= back.first;
            }
            if (st.empty())
            {
                stack_sum = maxHeights[i] * (i + 1);
            }
            else
                stack_sum += maxHeights[i] * (i - st.back().second);
            st.push_back({maxHeights[i], i});
        }
        left[i] = stack_sum;
        // left[i] = st.front().second * st.front().first + stack_sum;
    }
    // for (auto i : left)
    //     cout << i << "  ";
    // cout << endl;
    st.clear();
    stack_sum = 0;
    vector<long long> right(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty() || maxHeights[i] >= st.back().first)
        {
            stack_sum += maxHeights[i];
            st.push_back({maxHeights[i], i});
        }
        else
        {
            while (!st.empty() && maxHeights[i] < st.back().first)
            {
                pair<int, int> back = st.back();
                st.pop_back();

                if (!st.empty())
                    stack_sum -= (st.back().second - back.second) * (back.first);
                else
                    stack_sum -= back.first;
            }
            if (st.empty())
            {
                stack_sum = maxHeights[i] * (n - i);
            }
            else
            {
                stack_sum += (st.back().second - i) * maxHeights[i];
                // stack_sum += maxHeights[i];
            }
            st.push_back({maxHeights[i], i});
        }
        right[i] = stack_sum;
        // right[i] = (n - st.front().second - 1) * st.front().first + stack_sum;
    }
    for (auto i : right)
        cout << i << "  ";
    cout << endl;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        ans[i] = left[i] + right[i] - maxHeights[i];
    }
    for (auto i : ans)
        cout << i << "  ";
    cout << endl;
}