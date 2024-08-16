#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline

    Job(int id, int dead, int profit)
    {
        this->id = id;
        this->dead = dead;
        this->profit = profit;
    }
};
bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}
vector<int> JobScheduling(vector<Job> arr, int n)
{
    // your code here
    // sort(arr, arr + n, compare);
    sort(arr.begin(), arr.end(), compare);

    int max_dead = arr[0].dead;

    for (int i = 1; i < n; i++)
    {
        max_dead = max(max_dead, arr[i].dead);
    }

    vector<int> slot(max_dead+1, -1);

    int count_jobs = 0;
    int total_profit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = arr[i].id;
                total_profit = total_profit + arr[i].profit;
                count_jobs++;
                break;
            }
        }
    }
    vector<int> ans;
    ans.push_back(count_jobs);
    ans.push_back(total_profit);
    return ans;
}

int main()
{
    vector<Job> arr = {Job(1, 2, 100), Job(2, 1, 19), Job(3, 2, 27), Job(4, 1, 25), Job(5, 1, 15)};
    // vector<Job> arr={Job(1,4,20),Job(2,1,10),Job(3,1,40),Job(4,1,30)};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans = JobScheduling(arr, 5);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}