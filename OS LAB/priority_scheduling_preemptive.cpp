#include <bits/stdc++.h>
using namespace std;
class jobs
{
public:
    int arrival;
    int burst;
    int time_left;
    int id;
    int priority;
    int ct;
    int tat;
    int wt;
};
bool func(jobs a, jobs b)
{
    return a.arrival < b.arrival;
}

void priority_premptive(vector<int> arrival, vector<int> burst, vector<int> ID, vector<int> pri)
{
    int n = arrival.size();
    vector<jobs> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].arrival = arrival[i];
        arr[i].burst = burst[i];
        arr[i].time_left = burst[i];
        arr[i].id = ID[i];
        arr[i].priority = pri[i];
    }
    sort(arr.begin(), arr.end(), func);

    priority_queue<pair<int, jobs *>> pq;
    int curr_time = 0;
    int curr_ind = 0;
    pq.push({arr[0].priority, &arr[0]});
    curr_time = arr[0].arrival;
    curr_ind++;
    while (!pq.empty())
    {
        while (curr_ind < n && curr_time >= arr[curr_ind].arrival)
        {
            pq.push({arr[curr_ind].priority, &arr[curr_ind]});
            curr_ind++;
        }
        if (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            // top.first--;
            top.second->time_left--;
            if (top.second->time_left == 0)
            {
                top.second->ct = curr_time + 1;
                // pq.pop();
            }

            if (top.second->time_left > 0)
                pq.push(top);
        }
        curr_time++;
    }
    int total_tat = 0;
    int total_wt = 0;
    cout << "ID"
         << "\t"
         << "arrival"
         << "\t"
         << "burst"
         << "\t"
         << "completion\t"
         << "TAT\t"
         << "WT" << endl;
    for (int i = 0; i < n; i++)
    {
        arr[i].tat = arr[i].ct - arr[i].arrival;
        arr[i].wt = arr[i].ct - arr[i].arrival - arr[i].burst;
        if (arr[i].wt < 0)
            arr[i].wt = 0;
        total_tat += arr[i].tat;
        total_wt += arr[i].wt;
        cout << arr[i].id << "\t" << arr[i].arrival << "\t" << arr[i].burst << "\t" << arr[i].ct << "\t\t" << arr[i].tat << "\t" << arr[i].wt << endl;
    }
    cout << "AVERAGE WAITING TIME: " << (double)total_wt / n << endl;
    cout << "AVERAGE TURN AROUND TIME: " << (double)total_tat / n << endl;
}
int main()
{
    vector<int> arrival = {0,1,2,2}, burst_t = {2,3,2,1}, Pid = {1,2,3,4}, pri = {0,2,3,1};
    priority_premptive(arrival, burst_t, Pid, pri);
}