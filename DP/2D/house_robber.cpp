#include <bits/stdc++.h>
using namespace std;
int rob(vector<int> &nums)
{
    int n = nums.size();
    int a = 0;
    int b = nums[0];
    for (int i = 1; i < n; i++)
    {
        int temp = a;
        a = b;
        b = max(nums[i] + temp, b);
    }
    return b;
}
int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << rob(nums);
}