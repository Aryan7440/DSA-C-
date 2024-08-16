#include <bits/stdc++.h>
using namespace std;
int minMoves(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int j = 1;
    int steps = 0;
    int n = nums.size();
    for (int i = n - 1; i > 0; i--)
    {
        steps += (nums[i] - nums[i - 1]) * j;
        j++;
    }
    return steps;
}
int main()
{
    vector<int> nums={1,2,3};
    cout<<minMoves(nums);
}