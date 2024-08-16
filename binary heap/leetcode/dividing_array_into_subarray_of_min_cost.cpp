#include <bits/stdc++.h>
using namespace std;
long long minimumCost(vector<int> &nums, int k, int dist)
{
    int n = nums.size();
    int l = 1, r = l;
    multiset<int, greater<int>> pq;
    multiset<int> pq1;
    int sum = nums[0];
    int ans = INT_MAX;
    while (r < n && pq.size() < k - 1 && r <= l + dist)
    {
        pq.insert(nums[r]);
        sum += nums[r++];
    }
    while (r < n && r <= l + dist)
    {
        if (*pq.begin() > nums[r])
        {
            pq1.insert(*pq.begin());
            sum -= *pq.begin();
            pq.erase(pq.begin());
            pq.insert(nums[r]);
            sum += nums[r++];
        }
        else
            pq1.insert(nums[r++]);
    }
    ans = min(ans, sum);
    while (r < n)
    {
        int num = nums[l];
        if (pq1.find(num) != pq1.end())
        {
            pq1.erase(pq1.find(num));
        }
        else
        {
            pq.erase(pq.find(num));
            sum -= num;
            if (pq1.size() > 0)
            {
                pq.insert(*pq1.begin());
                sum += *pq1.begin();
                pq1.erase(pq1.begin());
            }
        }
        if (nums[r] < *pq.begin() || pq.size() < k - 1)
        {
            if (pq.size() == k - 1)
            {
                pq1.insert(*pq.begin());
                sum -= *pq.begin();
                pq.erase(pq.begin());
                sum += nums[r];
                pq.insert(nums[r++]);
            }
            else
            {
                pq.insert(nums[r]);
                sum += nums[r++];
            }
        }
        else
            pq1.insert(nums[r++]);
        ans = min(ans, sum);
        l++;
    }
    return ans;
}
int main()
{
    // vector<int> nums = {10, 1, 2, 2, 2, 1};
    // vector<int> nums = {10, 8, 18, 9};
    // vector<int> nums = {1, 3, 2, 6, 4, 2};
    vector<int> nums = {1, 5, 3, 7};
    // int k = 4, dist = 3;
    int k = 3, dist = 1;
    // int k = 3, dist = 1;
    // int k = 3, dist = 3;
    cout << minimumCost(nums, k, dist);
}