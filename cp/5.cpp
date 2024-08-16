#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> ds, int a, int k)
{
    for (int i = 0; i < ds.size(); i++)
    {
        if ((a + ds[i]) % k == 0)
            return false;
    }
    return true;
}
void sub_seq(vector<int> arr, int i, int k, vector<int> &ds, set<vector<int>> &s)
{
    if (i == arr.size())
    {
        s.insert(ds);
        return;
    }
    if (check(ds, arr[i], k))
    {
        ds.push_back(arr[i]);
        sub_seq(arr, i + 1, k, ds, s);
        ds.pop_back();
    }
    sub_seq(arr, i + 1, k, ds, s);
}
int main()
{
    // your code goes here
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        int n;
        // cin >> n;
        n = 3;
        int k;
        // cin >> k;
        k = 4;
        vector<int> arr = {4, 5, 7};
        // for (int i = 0; i < n; i++)
        // {
        //     int temp;
        //     cin >> temp;
        //     arr.push_back(temp);
        // }
        vector<int> ds;
        set<vector<int>>s;
        sub_seq(arr, 0, k,ds,s);
        cout<< s.size();
        
    }
    return 0;
}
