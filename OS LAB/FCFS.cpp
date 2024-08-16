#include <bits/stdc++.h>
using namespace std;

void FCFS(vector<int> &arrival, vector<int> burst_T)
{
    vector<pair<int, int>> jobs;
    for (int i = 0; i < arrival.size(); i++)
    {
        jobs.push_back({arrival[i], burst_T[i]});
    }
    sort(jobs.begin(), jobs.end());
    cout << "PN\tAT\t"<< "BT\tWT\tTAT\n";
    int tat=jobs[0].second;
    cout << "1"<< "\t" << jobs[0].first << "\t" << jobs[0].second << "\t" << 0 <<"\t"<<tat<< endl;
    int wt=0;
    int sum=0;
    int sum_tat=0;
    for (int i = 1; i < jobs.size(); i++)
    {
        wt=jobs[i-1].first+jobs[i-1].second+wt-jobs[i].first;
        if(wt<0)wt=0;
        sum+=wt;
        tat=(jobs[i].second+wt);
        sum_tat+=tat;
        cout << i+1<< "\t" << jobs[i].first << "\t" << jobs[i].second << "\t" << wt << "\t"<<tat<<endl;
    }

    cout<<"AVERAGE WAITING TIME: "<<(double)sum/jobs.size()<<endl;
    cout<<"AVERAGE TURN AROUND TIME TIME: "<<(double)sum_tat/jobs.size()<<endl;
}
int main()
{
    vector<int> arrival = { 0, 1, 5,6};
    // vector<int> arrival = { 0, 1, 2, 3, 4 };
    // Array for Burst Time
    vector<int>burst_T = {2,2,3,4};
    // vector<int>burst_T = { 4, 3, 1, 2, 5 };
    FCFS(arrival,burst_T);
}