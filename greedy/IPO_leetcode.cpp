#include <bits/stdc++.h>
using namespace std;
int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
    int n = profits.size();
    vector<pair<int, int>> arr;
    for (int i = 0; i < profits.size(); i++)
        arr.push_back({capital[i], profits[i]});
    sort(arr.begin(), arr.end());
    int inv = 0;
    priority_queue<pair<int, int>> pq;
    while (arr[inv].first <= w && inv < n)
    {
        pq.push({arr[inv].second, arr[inv].first});
        inv++;
    }
    int jobs = 0;
    while (!pq.empty() && jobs < k)
    {
        w += pq.top().first;
        pq.pop();
        jobs++;
        while (arr[inv].first <= w && inv < n)
        {
            pq.push({arr[inv].second, arr[inv].first});
            inv++;
        }
    }
    return w;
}
int main()
{
    vector<int> profits = {1, 2, 3}, capital = {0, 1, 1};
    cout << findMaximizedCapital(3, 0, profits, capital);
}