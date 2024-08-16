#include <bits/stdc++.h>
using namespace std;

int canJump(vector<int> &nums)
{
    int curr=0;
    int jumps=0;
    int reach=0;
    for(int i=0;i<nums.size();i++)
    {
        reach=max(reach,i+nums[i]);
        if(i==curr && i!=nums.size()-1)
        {
            jumps++;
            curr=reach;
        }
    }
    return jumps;
}

int main()
{
    vector<int> nums = {7, 0, 9, 6, 9, 6, 1, 7, 9, 0, 1, 2, 9, 0, 3};
    cout << canJump(nums) << endl;
}