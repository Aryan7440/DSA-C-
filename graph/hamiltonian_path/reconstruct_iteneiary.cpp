#include <bits/stdc++.h>
using namespace std;
vector<string> findItinerary(vector<vector<string>> &tickets)
{
    unordered_map<string, vector<string>> adj;

    for (auto i : tickets)
    {
        adj[i[0]].push_back(i[1]);
    }
    for (auto &i : adj)
    {
        sort(i.second.begin(), i.second.end(),greater<string>());
        // reverse(i.second.begin(), i.second.end());
    }
    stack<string> st;
    vector<string> ans;
    st.push("JFK");
    while (!st.empty())
    {
        string s = st.top();
        if (adj[s].empty())
        {
            ans.push_back(s);
            st.pop();
        }
        else
        {
            string next = adj[s].back();
            st.push(next);
            adj[s].pop_back();
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<vector<string>> tickets = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
    vector<string> ans = findItinerary(tickets);
    for (auto i : ans)
        cout << i << " ";
}