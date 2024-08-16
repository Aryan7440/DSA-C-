#include<bits/stdc++.h>
using namespace std;
vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> st;
        int n=nums.size();
        // int count=n-k;
        for(int i=0;i<n;i++)
        {
            if((st.size()<k && (st.empty() || st.back()<=nums[i])))
            {
                st.push_back(nums[i]);
            }
            else 
            {
                while(!st.empty() && st.back()>nums[i] && k-st.size()<n-i)st.pop_back();
                if(st.size()<k)st.push_back(nums[i]);
            }
        }
        return st; 
    }
    int main()
    {
        vector<int> nums={2,4,3,3,5,4,9,6};
        vector<int> ans=mostCompetitive(nums,4);
        for(auto i:ans)cout<<i<<" ";
    }