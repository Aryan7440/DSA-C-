#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
    int i = 0, j = 0;
    int ans = 0;
    int z=0;
    while(j<nums.size())
    {
        if(nums[j]==0)z++;
        while (z>k)
        {
            if(nums[i]==0)z--;
            i++;
        }
        ans=max(ans,j-i+1);
        j++;
    }
    return ans;
}
int main()
{
    // vector<int> nums = {0, 0, 1, 1, 1, 0, 0};
    // cout << longestOnes(nums, 0);
    // vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    // cout << longestOnes(nums, 3)<<endl;
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    cout << longestOnes(nums, 2);
    
}