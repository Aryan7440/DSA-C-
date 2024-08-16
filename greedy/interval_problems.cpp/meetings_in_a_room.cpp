#include <bits/stdc++.h>
using namespace std;

bool sortbysec(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(make_pair(start[i], end[i]));
    }
    sort(v.begin(), v.end(), sortbysec);
    int ans = 0;
    int prev = 0;
    for (auto i : v)
    {
        if (i.first >= prev)
        {
            ans++;
            prev = i.second;
        }
        
    }
    return ans;
}

int main()
{
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    cout<<maxMeetings(start,end,6);
}