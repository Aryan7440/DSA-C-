#include <bits/stdc++.h>
#include "DS.h"
using namespace std;

disjoint_set ds;
bool comp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}
vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
{
    ds.resize(n);
    ds.union_bysize(0, firstPerson);
    sort(meetings.begin(), meetings.end(), comp);
    for (int i = 0; i < meetings.size(); i++)
    {
        if (ds.find_parent(0) == ds.find_parent(meetings[i][0]) || ds.find_parent(0) == ds.find_parent(meetings[i][1]))
        {
            ds.union_bysize(0, meetings[i][0]);
            ds.union_bysize(0, meetings[i][1]);
        }
    }
    vector<int> ans = {0};
    for (int i = 1; i < n; i++)
    {
        if (ds.find_parent(0) == ds.find_parent(i))
            ans.push_back(i);
    }
    return ans;
}
int main()
{
}