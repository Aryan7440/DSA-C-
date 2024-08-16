#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m;
    cin >> n >> m;
    queue<long long> q;
    unordered_set<long long> st;
    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        q.push(x);
        st.insert(x);
    }
    vector<long long> ans;

    long long count = 0;
    long long c = 1;
    while (!q.empty())
    {
        long long sz = q.size();
        for (long long i = 0; i < sz; i++)
        {
            long long x = q.front();
            q.pop();
            if (st.find(x - 1) == st.end())
            {
                ans.push_back(x - 1);
                st.insert(x - 1);
                count += c;
                q.push(x - 1);
            }
            if (ans.size() == m)
            {
                break;
            }
            if (st.find(x + 1) == st.end())
            {
                ans.push_back(x + 1);
                st.insert(x + 1);
                count += c;
                q.push(x + 1);
            }
            if (ans.size() == m)
            {
                break;
            }
        }
        if (ans.size() == m)
        {
            break;
        }
        c++;
    }
    cout << count << '\n';

    for (long long i = 0; i < m; i++)
    {
        cout << ans[i] << " ";
    }
}