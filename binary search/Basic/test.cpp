#include<bits/stdc++.h>
using namespace std;
int MAX(vector<int> nums)
{
    int MAXi=0;
    for(auto i:nums)MAXi=max(MAXi,i);
    return MAXi;
}
int main(int argc, char const *argv[])
{
    vector<int> nums={21,1521,125};
    cout<<MAX(nums);
    return 0;
}
