#include <bits/stdc++.h>

using namespace std;
int countCompleteSubarrays(vector<int> &nums)
{
    int n = nums.size();
    int l = 0, r = 0, ans = 0;
    unordered_map<int, int> mp;
    int count = 0;
    for (auto i : nums)
    {
        if (mp[i] == 0)
            count++;
        mp[i]++;
    }
    unordered_map<int, int> mp2;
    int c = 0;
    while (r < n && l < n)
    {
        if (mp2[nums[r]] == 0)
            c++;
        mp2[nums[r]]++;

        while (c == count)
        {
            ans += n - r;
            mp2[nums[l]]--;
            if (mp2[nums[l]] == 0)
                c--;
            l++;
        }
        r++;
    }
    return ans;
}

int main()
{
    vector<int> nums={1898,370,822,1659,1360,128,370,360,261,1898};
    cout<<countCompleteSubarrays(nums);
}