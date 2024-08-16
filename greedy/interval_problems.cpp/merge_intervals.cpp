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
bool compare(vector<int> v1, vector<int> v2)
{
    return v1[0] < v2[0];
}
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(),compare);
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        if (ans.back()[1] < intervals[i][0])
        {
            ans.push_back(intervals[i]);
        }
        else if (ans.back()[1] < intervals[i][1])
        {
            ans.back()[1]=intervals[i][1];
        }      
    }
    return ans;
}

int main()
{
    vector<vector<int>> intervals = {{1, 4}, {0,2}, {3,5}};
    // sort(intervals.begin(), intervals.end(), compare);
    vector<vector<int>> ans=merge(intervals);
    display(ans);
}