#include <bits/stdc++.h>
using namespace std;
void combination_sum(vector<int> v, vector<int> &arr, int n, int k, vector<vector<int>> &ans)
{
    

    if (k == 0) // sum of subset elemets is equal to k
    {
        ans.push_back(arr);
        return;
    }
    if (n == v.size())  // all elements are considered
    {
        return;
    }
    if (v[n] <= k)  // if element is smaller than target then only consider otherwise exclude
    {
        arr.push_back(v[n]);
        combination_sum(v, arr, n + 1, k - v[n], ans);
        arr.pop_back();// for backtrack
    }
    combination_sum(v, arr, n + 1, k, ans);// for next element
    return;
}
void display(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> a = {1, 2, 1};
    vector<vector<int>> v;// stores all subset with sum equal to k
    vector<int> arr;
    combination_sum(a, arr, 0, 2, v);
    display(v);
}