#include <bits/stdc++.h>
using namespace std;
int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
{
    unordered_map<int, vector<int>> mp;
    queue<int> q;
    unordered_set<int> st;
    for (int i = 0; i < routes.size(); i++)
    {
        for (int j = 0; j < routes[i].size(); j++)
        {
            mp[routes[i][j]].push_back(i);
            if (routes[i][j] == source)
            {
                q.push(i);
                st.insert(i);
            }
        }
    }

    int count = 0;

    while (!q.empty())
    {
        count++;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            int bus = q.front();
            q.pop();
            for (auto station : routes[bus])
            {
                if (station == target)
                    return count;
                for (auto j : mp[station])
                {
                    if (st.find(j) == st.end())
                    {
                        st.insert(j);
                        q.push(j);
                    }
                }
            }
        }
    }
    return -1;
}
int main()
{
    vector<vector<int>> routes={{1,2,7},{3,6,7}};
    cout<<numBusesToDestination(routes,1,6);
}