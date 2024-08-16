#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// void perm1(vector<int> arr, vector<int> &ds, unordered_map<int, int> &mp, vector<vector<int>> &ans)
// {
//     if (ds.size() == arr.size())
//     {
//         ans.push_back(ds);
//         return;
//     }
//     for (int i = 0; i < arr.size(); i++)
//     {
//         if (mp.find(arr[i]) == mp.end())
//         {
//             ds.push_back(arr[i]);
//             mp[arr[i]] = 1;
//             perm1(arr, ds, mp, ans);
//             mp.erase(arr[i]);
//             ds.pop_back();
//         }
//     }
// }
// vector<vector<int>> permutation1(vector<int> &arr) // wont work on array with non-distinct values
// {
//     vector<vector<int>> ans;
//     vector<int> ds;
//     unordered_map<int, int> mp;
//     perm1(arr, ds, mp, ans);
//     return ans;
// }

void permutation_(vector<int> &arr, int ind, vector<vector<int>> &ans)
{
    if (ind == arr.size()) 
    {
        ans.push_back(arr);
        return;
    }
    for (int i = ind; i < arr.size(); i++)
    {
        swap(arr[ind], arr[i]);
        permutation_(arr, ind + 1, ans);
        swap(arr[ind], arr[i]);
    }
}

vector<vector<int>> permutation(vector<int> &arr)
{
    vector<vector<int>> ans;
    permutation_(arr, 0, ans);
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans = permutation(arr);
    display(ans);
}