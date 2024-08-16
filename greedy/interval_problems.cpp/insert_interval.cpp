#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> interval)
{
    for (auto i : interval)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> ans;
    if (intervals.size() == 0)
    {
        ans.push_back(newInterval);
        return ans;
    }
    int i = 0;
    int n=intervals.size();
    while (i<n && intervals[i][1] < newInterval[0])
    {
        ans.push_back(intervals[i]);
        i++;
    }

    while (i<n && newInterval[1] >= intervals[i][0])
    {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    ans.push_back(newInterval);
    while (i < intervals.size())
    {
        ans.push_back(intervals[i]);
        i++;
    }
    return ans;
}

int main()
{
    vector<vector<int>> intervals = {{1,5}};
    vector<int> newInterval = {2,3};
    vector<vector<int>> ans = insert(intervals, newInterval);
    display(ans);
}