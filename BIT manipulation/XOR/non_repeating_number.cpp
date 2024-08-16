#include<bits/stdc++.h>
using namespace std;
int non_repeating(vector<int>&arr)
{
    int n=arr.size();
    int XOR=0;
    for(auto i:arr)
    {
        XOR=XOR^i;
    }
    return XOR;
}
int main()
{
    vector<int> arr={2,2,5,7,0,2,5,1,1,2,7};
    cout<<non_repeating(arr);
}