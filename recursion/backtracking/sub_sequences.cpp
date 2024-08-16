#include <bits/stdc++.h>
using namespace std;
void display(vector<int> arr)
{
    if (arr.size() == 0)
        cout << "NULL" << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

// void sub_sequence(vector<int> arr, int n, vector<int> &ans)
// {
//     if (n >= arr.size())
//     {
//         display(ans);
//         return;
//     }
//     ans.push_back(arr[n]);
//     n++;
//     sub_sequence(arr, n, ans);
//     ans.pop_back();
//     sub_sequence(arr, n, ans);
// }

void sub_sequence(vector<int> arr, int n, vector<int> &ans, vector<vector<int>> &Ans)
{
    if (n == arr.size())
    {
        Ans.push_back(ans);
        return;
    }
    ans.push_back(arr[n]);
    sub_sequence(arr, n+1, ans, Ans);
    ans.pop_back();
    sub_sequence(arr, n+1, ans, Ans);
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> Ans;
    vector<int> ans;
    sub_sequence(nums, 0, ans, Ans);
    return Ans;
}

void display2(vector<vector<int>> arr)
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

int main()
{
    vector<int> arr = {3, 2, 1};
    vector<int> ans;
    // sub_sequence(arr, 0, ans);
    vector<vector<int>> Arr;
    Arr = subsets(arr);
    display2(Arr);
}