#include <bits/stdc++.h>
using namespace std;
int minSubArrayLen(int target, vector<int> &nums)
{
    int i = 0, j = -1;
    int count = INT_MAX;
    int sum = 0;
    int n=nums.size();
    while (j < n-1)
    {
        if (sum <= target)
        {
            j++;
            sum = sum + nums[j];
        }
        else if (sum > target)
        {
            sum = sum - nums[i];
            i++;
        }
        if (sum == target)
        {
            count = min(j - i + 1, count);
        }
    }
    return (count==INT_MAX)? 0:count;
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    cout << minSubArrayLen(11, arr);
}