#include <bits/stdc++.h>
using namespace std;
int mostBooked(int n, vector<vector<int>> &meetings)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    set<int> rooms;
    for (int i = 0; i < n; i++)
        rooms.insert(i);
    vector<int> count(n, 0);
    sort(meetings.begin(), meetings.end());
    for (int i = 0; i < meetings.size(); i++)
    {
        while (!pq.empty() && pq.top().first < meetings[i][0])
        {
            int rm = pq.top().second;
            rooms.insert(rm);
            pq.pop();
        }
        if (!pq.empty() && rooms.empty())
        {
            int t = pq.top().first;
            int rm = pq.top().second;
            rooms.insert(rm);
            pq.pop();
            meetings[i][1] += t - meetings[i][0];
            meetings[i][0] = t;
        }
        int avr = *rooms.begin();
        rooms.erase(rooms.begin());
        count[avr]++;
        pq.push({meetings[i][1], avr});
    }
    int ans = -1;
    int mx = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (count[i] >= mx)
        {
            ans = i;
            mx = count[i];
        }
    }
    return ans;
}
int main()
{
    int n = 4;
    vector<vector<int>> meetings = {{48, 49}, {22, 30}, {13, 31}, {31, 46}, {37, 46}, {32, 36}, {25, 36}, {49, 50}, {24, 34}, {6, 41}};
    // vector<vector<int>> meetings = {{0, 10}, {1, 5}, {2, 7}, {3, 4}};
    cout << mostBooked(n, meetings);
}