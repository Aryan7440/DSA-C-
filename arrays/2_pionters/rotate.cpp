#include <bits/stdc++.h>
using namespace std;
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> ans;
    for (int i = (n - k)%n; i <= 2*n - k; i++)
        ans.push_back(nums[(i)% n]);
    for (int j = 0; j < n; j++)
        nums[j] = ans[j];
}
int main()
{
    // vector<int> nums = {1,2,3,4,5,6};
    // int k = 3;
    // rotate(nums,1);
    // for(auto i:nums)cout<<i<<" ";

    string s;
    getline(cin,s);
    cout<<s;
}