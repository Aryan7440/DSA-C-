#include<bits/stdc++.h>
using namespace std;

bool util(vector<int>&nums,int i,int k)
{
    if(i==nums.size() || k<0)return false;
    if(k==0)return true;
    bool take,not_take;
    if(util(nums,i+1,k-nums[i]))return true;
    else if(util(nums,i+1,k))return true;
    return false;
}
int main()
{
    vector<int>nums={1,5,2};
    cout<<util(nums,0,4);
}