#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zero_sum(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    int i = 0;
    while (i < arr.size())
    {
        int l = i + 1, r = arr.size() - 1;
        while (l < r)
        {
            if (arr[l] + arr[r] == (-arr[i]))
            {
                vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[l]);
                temp.push_back(arr[r]);
                ans.push_back(temp);
                l++;
                r--;
                while (arr[l] == arr[l - 1])
                {
                    l++;
                }
                while (arr[r] == arr[r + 1])
                {
                    r--;
                }
            }
            else if (arr[l] + arr[r] > (-arr[i]))
            {
                r--;
                while (arr[r] == arr[r + 1])
                {
                    r--;
                }
            }
            else
            {
                l++;
                while (arr[l] == arr[l - 1])
                {
                    l++;
                }
            }
        }
        i++;
        while (arr[i] == arr[i - 1])
        {
            i++;
        }
    }
    return ans;
}
vector<vector<int>> three_sum(vector<int> arr,int k)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    int i = 0;
    while (i < arr.size())
    {
        int l = i + 1, r = arr.size() - 1;
        while (l < r)
        {
            if (arr[l] + arr[r] == (k-arr[i]))
            {
                vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[l]);
                temp.push_back(arr[r]);
                ans.push_back(temp);
                l++;
                r--;
                while (arr[l] == arr[l - 1])
                {
                    l++;
                }
                while (arr[r] == arr[r + 1])
                {
                    r--;
                }
            }
            else if (arr[l] + arr[r] > (k-arr[i]))
            {
                r--;
                while (arr[r] == arr[r + 1])
                {
                    r--;
                }
            }
            else
            {
                l++;
                while (arr[l] == arr[l - 1])
                {
                    l++;
                }
            }
        }
        i++;
        while (arr[i] == arr[i - 1])
        {
            i++;
        }
    }
    return ans;
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
    vector<int> v = {1 ,1, 2, 2, 1, 1};
    // vector<vector<int>> z = zero_sum(v);
    vector<vector<int>> z = three_sum(v,4);
    display(z);
}