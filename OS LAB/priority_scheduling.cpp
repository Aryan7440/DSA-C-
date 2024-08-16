#include<bits/stdc++.h>
using namespace std;
class job
{
public:
    int arrival;
    int burst;
    int priority;
    int id;
    int ct;
    int tat;
    int wt;
};
bool func(job a, job b)
{
    return a.arrival < b.arrival;
}
struct Comp{
    bool operator()(pair<int,job*> a, pair<int,job*>  b){
        if(a.first==b.first)return a.second->arrival<b.second->arrival;//same pri gets excecuted on FCFS basis
        return a.first<b.first;
    }
};
void PRIORITY_SCHEDULING(vector<int> &Pid, vector<int> &arrival, vector<int> &burst_t,vector<int>&priority)
{
    int n = arrival.size();
    vector<job> jobs(n);
    for (int i = 0; i < n; i++)
    {
        jobs[i].arrival=arrival[i];
        jobs[i].id=Pid[i];
        jobs[i].burst=burst_t[i];
        jobs[i].priority=priority[i];
    }
    sort(jobs.begin(), jobs.end(),func);

    priority_queue<pair<int, job*>, vector<pair<int, job*>>, Comp> pq;
    int curr_process = 0;
    int time = 0;
    while (!pq.empty() || curr_process < n)
    {
        if (pq.empty())
            time = max(time, jobs[curr_process].arrival);
        while (curr_process < n && time >= jobs[curr_process].arrival)
        {
            pq.push({jobs[curr_process].priority, &jobs[curr_process]});
            curr_process++;
        }
        auto top=pq.top();
        int pid = top.second->id;
        int bt = top.second->burst;
        top.second->wt = time - arrival[pid];
        time = time + bt;
        top.second->ct = time;
        top.second->tat = top.second->wt + bt;
        pq.pop();
    }
    int total_tat=0;
    int total_wt=0;
    cout<<"ID"<<"\t"<<"arr"<<"\t"<<"pri\t"<<"comp\t"<<"TAT\t"<<"WT"<<endl;
    for(int i=0;i<n;i++)
    {
        jobs[i].tat=jobs[i].ct-jobs[i].arrival;
        jobs[i].wt=jobs[i].ct-jobs[i].arrival-jobs[i].burst;
        if(jobs[i].wt<0)jobs[i].wt=0;
        total_tat+=jobs[i].tat;
        total_wt+=jobs[i].wt;
        cout<<jobs[i].id<<"\t"<<jobs[i].arrival<<"\t"<<jobs[i].priority<<"\t"<<jobs[i].ct<<"\t"<<jobs[i].tat<<"\t"<<jobs[i].wt<<endl;
    }
    cout<<"AVERAGE WAITING TIME: "<<(double)total_wt/n<<endl;
    cout<<"AVERAGE TURN AROUND TIME: "<<(double)total_tat/n<<endl;
}
int main()
{
    vector<int>Pid={1,2,3,4},arrival={0,1,2,3},burst={5,3,8,6},priority={1,2,1,3};
    PRIORITY_SCHEDULING(Pid,arrival,burst,priority);
    
}