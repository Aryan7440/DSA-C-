#include <bits/stdc++.h>
using namespace std;

void generate(int n, string s)
{
    if (s.length() == n)
    {
        cout << s << endl;
        return;
    }
    if (s[s.length() - 1] == '1')
    {
        generate(n, s + '0');
    }
    else
    {
        generate(n, s + '1');
        generate(n, s + '0');
    }
}

void arr_without_consecutive_zero(vector<vector<int>> &ans, vector<int> &arr, int n)
{
    if (arr.size() == n)
    {
        ans.push_back(arr);
        return;
    }
    if (arr.size() == 0 || arr[arr.size() - 1] != 0)
    {
        arr.push_back(1);
        arr_without_consecutive_zero(ans, arr, n);
        arr.pop_back();

        arr.push_back(0);
        arr_without_consecutive_zero(ans, arr, n);
        arr.pop_back();
    }
    else if (arr[arr.size() - 1] == 0)
    {
        arr.push_back(1);
        arr_without_consecutive_zero(ans, arr, n);
        arr.pop_back();
    }
}

vector<vector<int>> for_array(int n)
{
    vector<vector<int>> ans;
    vector<int> arr;
    arr_without_consecutive_zero(ans, arr, n);
    return ans;
}
int main()
{
    // string s;
    // generate(3, s);

    // cout<<'1'- 48;

    vector<vector<int>> ans = for_array(3);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}