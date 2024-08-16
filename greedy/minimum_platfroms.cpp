#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2)
{
    return p1.second<p2.second;
}

int findPlatform(int arr[], int dep[], int n)
{
    // Your code here
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> t = {arr[i], dep[i]};
        p.push_back(t);
    }
    sort(p.begin(),p.end(),compare);
    int m=0;
}