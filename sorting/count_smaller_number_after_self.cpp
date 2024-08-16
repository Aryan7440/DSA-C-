#include <bits/stdc++.h>
using namespace std;
void merge(vector<pair<int, int>> &num, int start, int mid, int end, vector<int> &ans)
{
    int i = start;
    int j = mid + 1;
    int c = 0;
    vector<pair<int, int>> arr;
    while (i <= mid && j <= end)
    {
        int num1 = num[i].first;
        int num2 = num[j].first;
        if (num1 > num2)
        {
            c++;
            arr.push_back(num[j]);
            j++;
        }
        else //(num2>=num1)
        {
            ans[num[i].second] += c;
            arr.push_back(num[i]);
            i++;
        }
    }
    while (i <= mid)
    {
        ans[num[i].second] += c;
        arr.push_back(num[i]);
        i++;
    }
    while (j <= end)
    {
        c++;
        arr.push_back(num[j]);
        j++;
    }
    for (int i = start; i <= end; i++)
    {
        num[i] = arr[i - start];
    }
}
void count(vector<pair<int, int>> &num, int start, int end, vector<int> &ans)
{
    if (start >= end)
        return;
    int mid = start + (end - start) / 2;
    count(num, start, mid, ans);
    count(num, mid + 1, end, ans);

    merge(num, start, mid, end, ans);
}
vector<int> countSmaller(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);
    vector<pair<int, int>> num;
    for (int i = 0; i < n; i++)
        num.push_back({nums[i], i});
    count(num, 0, n - 1, ans);
    return ans;
}
int main()
{
    vector<int> nums = {-1,-1};
    // vector<int> nums = {-1};
    // vector<int> nums = {5, 2, 6, 1};
    vector<int> ans = countSmaller(nums);
    for (auto i : ans)
        cout << i << " ";
}