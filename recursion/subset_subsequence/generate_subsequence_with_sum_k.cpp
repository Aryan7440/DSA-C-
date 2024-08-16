#include<bits/stdc++.h>
using namespace std;
void gen(vector<int>&nums,vector<int>&ds,int i,int k)
{
    if(k==0)
    {
        for(auto j:ds)cout<<j<<" ";
        cout<<endl;
        return;
    }
    if(k<0|| i==nums.size())return;
    ds.push_back(nums[i]);
    gen(nums,ds,i+1,k-nums[i]);
    ds.pop_back();
    gen(nums,ds,i+1,k);
}
int main()
{
    // vector<int>nums={1,2,2,3,4,5};
    vector<int>nums={1,0};
    // vector<int>nums={9 ,7 ,0 ,3 ,9 ,8 ,6 ,5 ,7 ,6};
    int k=1;
    vector<int>ds;
    gen(nums,ds,0,k);
}