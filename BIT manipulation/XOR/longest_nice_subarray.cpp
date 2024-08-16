#include <bits/stdc++.h>
using namespace std;
int longestNiceSubarray(vector<int> &nums)
{
    int map = 0;
    int i = 0;
    int j = 0;
    int n = nums.size();
    int ans = INT_MIN;
    while (j < n)
    {
        while ((map & nums[j]) != 0)
            map = map ^ nums[i++];
        map = map | nums[j];
        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
}
int main()
{
    vector<int> nums={1,3,8,48,10};
    cout<<longestNiceSubarray(nums);
}