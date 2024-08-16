#include <bits/stdc++.h>
using namespace std;
vector<int> help(vector<int> &nums, int m)
{
    vector<int> st;
    int n = nums.size();
    int r = n - m;
    for (int i = 0; i < n; i++)
    {
        if ((st.empty() || st.back() > nums[i]) && st.size() < m)
        {
            st.push_back(nums[i]);
        }
        else
        {
            while (!st.empty() && st.back() < nums[i] && r > 0)
            {
                st.pop_back();
                r--;
            }
            if (st.size() < m)
                st.push_back(nums[i]);
        }
    }
    return st;
}
vector<int> merge(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    int i = 0, j = 0;
    int n = nums1.size(), m = nums2.size();
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j])
        {
            int i1 = i;
            int j1 = j;
            while (i1 < n && j1 < m && nums1[i1] == nums2[j1])
            {
                i1++;
                j1++;
            }
            if (i1 < n && j1 < m && nums1[i1] > nums2[j1])
            {
                while (i < n && i < i1)
                {
                    ans.push_back(nums1[i]);
                    i++;
                }
            }
            else
            {
                while (j < m && j < j1)
                {
                    ans.push_back(nums2[j]);
                    j++;
                }
            }
        }
        else if (nums1[i] > nums2[j])
        {
            ans.push_back(nums1[i]);
            i++;
        }
        else
        {
            ans.push_back(nums2[j]);
            j++;
        }
    }
    while (i < nums1.size())
    {
        ans.push_back(nums1[i]);
        i++;
    }
    while (j < nums2.size())
    {
        ans.push_back(nums2[j]);
        j++;
    }
    return ans;
}
vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
{
    int n = nums1.size();
    int m = nums2.size();
    vector<int> ans;
    int num = 0;
    for (int i = 1; i <= k; i++)
    {
        if (k - i > m || i > n)
            continue;
        vector<int> a = help(nums1, i);
        vector<int> b = help(nums2, k - i);

        vector<int> res = merge(a, b);

        ans = max(ans, res);
        if (res.size() > ans.size())
            ans = res;
    }
    return ans;
}
int main()
{
    // vector<int> nums1 = {6, 7};
    // vector<int> nums2 = {6, 0, 4};
    // vector<int> nums1 = {3, 9};
    // vector<int> nums2 = {8, 9};
    vector<int> nums1 = {7, 6, 1, 9, 3, 2, 3, 1, 1};
    vector<int> nums2 = {4, 0, 9, 9, 0, 5, 5, 4, 7};
    // vector<int> nums1 = {5, 1, 0};
    // vector<int> nums2 = {5, 2, 1};
    // vector<int> nums1 = {5, 6, 8};
    // vector<int> nums2 = {6, 4, 0};
    // vector<int> nums1 = {3, 4, 6, 5};
    // vector<int> nums2 = {9, 1, 2, 5, 8, 3};
    // vector<int> ans = maxNumber(nums1, nums2, 5);
    vector<int> ans = maxNumber(nums1, nums2, 9);
    // vector<int> ans = maxNumber(nums1, nums2, 5);
    for (auto i : ans)
        cout << i << " ";
}