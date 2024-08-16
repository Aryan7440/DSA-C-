// 2.  write a prog to find out the subset of the array satisfying the following given conditions

// a. consider an array  a of int size and ele are taken as input
// take an int k as input from the user  your prog shuld be able to find out all possible combinations of array ind numbers for which the sum of array elements is equal to k if no such combinations is found print no such numbers are present in the array

#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void subsets_with_sum_k(vector<int> &arr, vector<int> &ds, int k, int sum, int i, vector<vector<int>> &ans)
{
    if (i == arr.size())
    {
        if (sum == k)
        {
            ans.push_back(ds);
        }
        return;
    }
    ds.push_back(arr[i]);
    subsets_with_sum_k(arr, ds, k, sum + arr[i], i + 1,ans);
    ds.pop_back();
    subsets_with_sum_k(arr, ds, k, sum, i + 1,ans);
}

int main()
{

    int n;
    cout << "enter NUMBER of elements:";
    cin >> n;
    vector<int> arr(n);
    cout << "enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    display(arr);
    vector<int> ds;

    int k;
    cout << "enter number k" << endl;
    cin >> k;
    cout << "SUB SETS WITH SUM K ARE:" << endl;
    vector<vector<int>> ans;
    subsets_with_sum_k(arr, ds, k, 0, 0,ans);
    if (ans.size() == 0)
    {
        cout << "there are no requred subsets!!" << endl;
    }
    else
    {
        for (int i = 0; i < ans.size(); i++)
        {
            display(ans[i]);
        }
        
    }
}
