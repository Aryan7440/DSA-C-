#include <bits/stdc++.h>
using namespace std;
int maximumSum(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pre(n, 0);
    int p_sum = 0;
    for (int i = 1; i <= n+1; i++)
    {
        pre[i] = p_sum;
        if (i <n )
            p_sum += arr[i];
        if (p_sum < 0)
            p_sum = 0;
    }
    int s_sum = 0;
    vector<int> suf(n, 0);
    for (int i = n-1; i >= 0; i--)
    {
        suf[i] = s_sum;
        if (i <n )
            s_sum += arr[i];
        if (s_sum < 0)
            s_sum = 0;
    }
    int ans = s_sum;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, pre[i] + suf[i]);
    }
    if (ans == 0)
    {
        ans = INT_MAX;
        for (int i = 0; i < n; i++)
            ans = min(ans, arr[i]);
    }
    return ans;
}
int main()
{
    vector<int> nums={1,-2,0,3};
    cout<<maximumSum(nums);
}