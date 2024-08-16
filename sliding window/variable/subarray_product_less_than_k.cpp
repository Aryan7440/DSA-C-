#include <bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int product = 1;
    int i = 0, j = 0;
    int count = 0;
    while (j < nums.size() && i < nums.size())
    {
        product = product * nums[j];
        while (product >= k && i < nums.size())
        {
            product = product / nums[i];
            i++;
        }
        count = (j - i + 1) < 0 ? 0 : count + j - i + 1;
        j++;
    }
    return count;
}
int main()
{
    vector<int> nums = {10, 9, 10, 4, 3, 8, 3, 3, 6, 2, 10, 10, 9, 3};
    // vector<int> nums={10,5,2,6};
    cout << numSubarrayProductLessThanK(nums, 19);
}