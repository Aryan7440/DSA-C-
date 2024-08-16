#include<bits/stdc++.h>
using namespace std;
int find_number_of_positives(vector<int>&nums)//find number of positive elements
{
    int n=nums.size();
    int l=0,r=n-1,mid=l+(r-l)/2;
    int res=-1;
    while(l<=r)//binary search of first negative element
    {
        mid=l+(r-l)/2;
        if(nums[mid]<0)
        {
            l=mid+1;
            res=mid;
        }
        else r=mid-1;
    }
    return n-res-1;
}

int main()
{
    vector<int> nums={-4,-3,-1,-1,-1,-1,-1,-1,0,0,0,0,1,2,3,4};
    cout<<find_number_of_positives(nums);
}