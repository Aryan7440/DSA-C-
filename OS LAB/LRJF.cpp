#include <bits/stdc++.h>
using namespace std;
class jobs
{
public:
    int arrival;
    int burst;
    int id;
    int ct;
    int tat;
    int wt;
};
bool func(jobs a, jobs b)
{
    return a.arrival < b.arrival;
}
struct Comp{
    bool operator()(pair<int,jobs*> a, pair<int,jobs*>  b){
        if(a.first==b.first)return a.second->arrival>b.second->arrival;
        return a.first<b.first;
    }
};

void lrjf(vector<int> arrival, vector<int> burst)
{
    int n = arrival.size();
    vector<jobs> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].arrival = arrival[i];
        arr[i].burst = burst[i];
        arr[i].id = i;
    }
    sort(arr.begin(), arr.end(), func);

    priority_queue<pair<int, jobs*>, vector<pair<int, jobs*>>, Comp> pq;
    int curr_time = 0;
    int curr_ind = 0;
    pq.push({arr[0].burst,&arr[0]});
    curr_time=arr[0].arrival;
    curr_ind++;
    while (!pq.empty())
    {
        while (curr_ind < n && curr_time >= arr[curr_ind].arrival)
        {
            pq.push({arr[curr_ind].burst, &arr[curr_ind]});
            curr_ind++;
        }
        if (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            top.first--;
            if (top.first == 0)
            {
                top.second->ct = curr_time+1;
            }
            
            if(top.first>0)pq.push(top);
        }
        curr_time++;
    }
    int total_tat=0;
    int total_wt=0;
    cout<<"ID"<<"\t"<<"arrival"<<"\t"<<"burst"<<"\t"<<"completion\t"<<"TAT\t"<<"WT"<<endl;
    for(int i=0;i<n;i++)
    {
        arr[i].tat=arr[i].ct-arr[i].arrival;
        arr[i].wt=arr[i].ct-arr[i].arrival-arr[i].burst;
        if(arr[i].wt<0)arr[i].wt=0;
        total_tat+=arr[i].tat;
        total_wt+=arr[i].wt;
        cout<<arr[i].id<<"\t"<<arr[i].arrival<<"\t"<<arr[i].burst<<"\t"<<arr[i].ct<<"\t\t"<<arr[i].tat<<"\t"<<arr[i].wt<<endl;
    }
    cout<<"AVERAGE WAITING TIME: "<<(double)total_wt/n<<endl;
    cout<<"AVERAGE TURN AROUND TIME: "<<(double)total_tat/n<<endl;
    
}
int main()
{
    vector<int> arrival = {1,2,3,4}, burst_t = {2,4,6,8}, Pid = { 1, 2, 3, 4};
    lrjf(arrival, burst_t);
}