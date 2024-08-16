#include <bits/stdc++.h>
using namespace std;

bool sortbysec(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    // pair<int,int>p;
    vector<int> start = {1, 3, 5, 5};
    vector<int> stop = {3, 2, 5, 4};
    vector<pair<int, int>> arr;
    for (int i = 0; i < 4; i++)
    {
        pair<int, int> p;
        p.first = start[i];
        p.second = stop[i];
        arr.push_back(p);
    }

    for (auto i : arr)
    {
        cout << i.first << " " << i.second << endl;
    }
    sort(arr.begin(), arr.end());
    for (auto i : arr)
    {
        cout << i.first << " " << i.second << endl;
    }
    sort(arr.begin(), arr.end(), sortbysec);
    for (auto i : arr)
    {
        cout << i.first << " " << i.second << endl;
    }
}