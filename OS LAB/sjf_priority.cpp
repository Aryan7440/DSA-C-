#include <bits/stdc++.h>
using namespace std;
class job
{
    public:
    int id;
    int arrival;
    int burst;
    int pri;
    int wt;
    int ct;
    int tat;
};
bool func(job a, job b)
{
    return a.arrival<b.arrival;
}
struct Comp{
    bool operator()(pair<int,job*> a, pair<int,job*>  b){
        // return a.first>b.first;
        if(a.first==b.first)
        {
            if(a.second->pri==b.second->pri)
            {
                return a.second->arrival>a.second->arrival;
            }
            else return a.second->pri>b.second->pri;
        }
        else return a.first>b.first;
    }
};
void print_pq(priority_queue<pair<int, job*>, vector<pair<int, job*>>, Comp> pq)
{
    while(!pq.empty())
    {
        cout<<pq.top().second->id<<" ";
        pq.pop();
    }
    cout<<endl;
}

void SJF(vector<int> &Pid, vector<int> &arrival, vector<int> &burst_t,vector<int> priority)
{
    int n = arrival.size();
    vector<job> jobs(n);
    for (int i = 0; i < n; i++)
    {
        jobs[i].arrival=arrival[i];
        jobs[i].id=Pid[i];
        jobs[i].burst=burst_t[i];
        jobs[i].pri=priority[i];
    }
    sort(jobs.begin(), jobs.end(),func);

    priority_queue<pair<int, job*>, vector<pair<int, job*>>, Comp> pq;
    int curr_process = 0;
    int time = 0;
    int p=1;
    while (!pq.empty() || curr_process < n)
    {
        
        if (pq.empty())
            time = max(time, jobs[curr_process].arrival);
        while (curr_process < n && time >= jobs[curr_process].arrival)
        {
            pq.push({jobs[curr_process].burst, &jobs[curr_process]});
            curr_process++;
        }
        auto top=pq.top();
        int pid = top.second->id;
        int bt = top.first;
        top.second->wt = time - arrival[pid];
        time = time + bt;
        top.second->ct = time;
        top.second->tat = top.second->wt + bt;
        cout<<"WAITING QUEUE AFTER "<<p++<<" process:"<<endl;
        print_pq(pq);
        pq.pop();
        
        
    }
    int total_tat=0;
    int total_wt=0;
    cout<<"ID"<<"\t"<<"arrival"<<"\t"<<"pri\t"<<"burst"<<"\t"<<"completion\t"<<"TAT\t"<<"WT"<<endl;
    for(int i=0;i<n;i++)
    {
        jobs[i].tat=jobs[i].ct-jobs[i].arrival;
        jobs[i].wt=jobs[i].ct-jobs[i].arrival-jobs[i].burst;
        if(jobs[i].wt<0)jobs[i].wt=0;
        total_tat+=jobs[i].tat;
        total_wt+=jobs[i].wt;
        cout<<jobs[i].id<<"\t"<<jobs[i].arrival<<"\t"<<jobs[i].pri<<"\t"<<jobs[i].burst<<"\t"<<jobs[i].ct<<"\t\t"<<jobs[i].tat<<"\t"<<jobs[i].wt<<endl;
    }
    cout<<"AVERAGE WAITING TIME: "<<(double)total_wt/n<<endl;
    cout<<"AVERAGE TURN AROUND TIME: "<<(double)total_tat/n<<endl;
}
int main()
{
    vector<int> arrival = {1,3,3,5,8,9}, burst_t = {2,2,3,3,3,3}, Pid = { 1, 2, 3, 4,5,6},priority={5,4,3,1,2,3};
    SJF(Pid, arrival, burst_t,priority);
}