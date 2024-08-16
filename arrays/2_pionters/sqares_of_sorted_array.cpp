#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    int i = 0;
    while (nums[i] < 0 && i<nums.size())
        i++;
    int j = (i == nums.size()) ? nums.size() - 1 : i;
    i++;
    vector<int> ans;
    while (i < nums.size() && j >= 0)
    {
        if (abs(nums[i]) < abs(nums[j]))
            ans.push_back(nums[i++]);
        else
            ans.push_back(nums[j--]);
    }
    while (i < nums.size())
        ans.push_back(nums[i++]);
    while (j >= 0)
        ans.push_back(nums[j--]);

    for (i = 0; i < ans.size(); i++)
        ans[i] = ans[i] * ans[i];
    return ans;
}
int main()
{
    vector<int> nums={-4};
    vector<int> ans=sortedSquares(nums);
    for(auto i:ans)cout<<i<<" ";
}