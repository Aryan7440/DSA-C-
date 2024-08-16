#include <bits/stdc++.h>
using namespace std;

vector<int> getOrder(vector<vector<int>> &tasks)
{
    for (int i = 0; i < tasks.size(); i++)
    {
        tasks[i].push_back(i);
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int time = 0;
    int i = 0;
    vector<int> ans;
    while (!pq.empty() || i < tasks.size())
    {
        if(pq.empty())
        {
            time=max(time,tasks[i][0]);
        }
        while (i<tasks.size() && time>=tasks[i][0])
        {
            pq.push({tasks[i][1],tasks[i][2]});
            i++;
        }
        time+=pq.top().first;
        ans.push_back(pq.top().second);
        pq.pop();
        
    }
    return ans;
}
int main()
{
    vector<vector<int>> tasks = {{1,2},{2,4},{3,2},{4,1}};
    vector<int> ans=getOrder(tasks);
    for(auto i: ans)cout<<i<<" ";
}