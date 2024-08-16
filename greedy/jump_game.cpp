#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums)
{
    int reach = 0;
    for (int i = 0; i < nums.size(); i++,reach--)
    {
        reach = max(reach, nums[i]);
        if (nums[i] == 0)
        {
            if (reach == 0 && i!=nums.size()-1 || i==0)
                return false;
        }
    }
    return true;
}
// bool canJump(vector<int> &nums)
// {
//     int reach = nums[0];
//     for (int i = 1; i < nums.size(); i++)
//     {
//         reach--;
//         if (nums[i] == 0)
//         {
//             if (reach == 0 && i!=nums.size()-1)
//                 return false;
//             else
//                 continue;
//         }
//         reach = max(reach, nums[i]);
//     }
//     return true;
// }

int main()
{
    vector<int> nums={2,0,0};
    cout<<canJump(nums);
}