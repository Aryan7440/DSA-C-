#include <bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int> &arr, int start, int end)
{
    // code here
    queue<int> q;
    vector<int> vis(100000, 0);
    vis[start] = 1;
    q.push(start);
    int ans = 0;
    while (!q.empty())
    {
        int n = q.size();
        ans++;
        for (int i = 0; i < n; i++)
        {
            auto p = q.front();
            q.pop();
            int res = p;
            for (int i = 0; i < arr.size(); i++)
            {
                int cur = (res * arr[i]) % 100000;
                if (!vis[cur])
                {
                    vis[cur] = ans;
                    if (cur == end)
                        return ans;
                    q.push(cur);
                }
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> arr={2,5,7};
    cout<<minimumMultiplications(arr,3,30);
}