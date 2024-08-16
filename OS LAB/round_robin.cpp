#include <bits/stdc++.h>
using namespace std;
class jobs
{
public:
    int arrival;
    int burst;
    int id;
    int time_left;
    int ct;
    int tat;
    int wt;
};
bool func(jobs a, jobs b)
{
    return a.arrival < b.arrival;
}
void round_robin(vector<int> Pid, vector<int> arr, vector<int> burst)
{
    int n = Pid.size();
    vector<jobs> job;
    for (int i = 0; i < n; i++)
    {
        jobs temp;
        temp.arrival = arr[i];
        temp.burst = burst[i];
        temp.time_left = burst[i];
        temp.id = Pid[i];
        job.push_back(temp);
    }
    sort(job.begin(), job.end(), func);
    int time_quantum;
    cout << "ENTER TIME QUANTUM: " << endl;
    cin >> time_quantum;
    int curr_time = 0;
    int curr_job = 0;
    int ct = 0;
    while (ct != n)
    {
        int t = 0;
        if (job[curr_job%n].time_left > 0)
        {
            while (job[curr_job%n].time_left > 0 && t < time_quantum)
            {
                job[curr_job%n].time_left--;
                t++;
            }
            if (job[curr_job%n].time_left == 0)
            {
                job[curr_job%n].ct = curr_time + t;
                ct++;
            }
        }
        curr_time += t;
        if (job[(curr_job + 1)%n].arrival <= curr_time)
        {
            curr_job++;
        }
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
        job[i].tat = job[i].ct - job[i].arrival;
        job[i].wt = job[i].ct - job[i].arrival - job[i].burst;
        if (job[i].wt < 0)
            job[i].wt = 0;
        total_tat += job[i].tat;
        total_wt += job[i].wt;
        cout << job[i].id << "\t" << job[i].arrival << "\t" << job[i].burst << "\t" << job[i].ct << "\t\t" << job[i].tat << "\t" << job[i].wt << endl;
    }
    cout << "AVERAGE WAITING TIME: " << (double)total_wt / n << endl;
    cout << "AVERAGE TURN AROUND TIME: " << (double)total_tat / n << endl;
}
int main()
{
    vector<int> Pid = {1, 2, 3, 4}, burst = {5, 4, 2, 1}, arrival = {0, 1, 2, 4};
    round_robin(Pid, arrival, burst);
}
