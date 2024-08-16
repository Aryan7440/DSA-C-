#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> &nums)
{
    int i = 0, j = 0;
    // int k = 0;
    vector<int> ans;
    while (i < nums.size() || j < nums.size())
    {
        while (i < nums.size() && nums[i] < 0)
            i++;
        // swap(nums[k], nums[i]);
        if (i < nums.size())
            ans.push_back(nums[i]);
        i++;
        // k++;
        while (j < nums.size() && nums[j] > 0)
            j++;
        // swap(nums[j], nums[k]);
        if (j < nums.size())
            ans.push_back(nums[j]);
        j++;
        // k++;
    }
    return ans;
}
int main()
{
    vector<int> nums = {28, -41, 22, -8, -37, 46, 35, -9, 18, -6, 19, -26, -37, -10, -9, 15, 14, 31};
    vector<int> ans = rearrangeArray(nums);
    for (auto i : ans)
        cout << i << " ";
}