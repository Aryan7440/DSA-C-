#include <bits/stdc++.h>
using namespace std;
static bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}
long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
{
    int sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<pair<int, int>> arr;
    for (int i = 0; i < nums1.size(); i++)
    {
        arr.push_back({nums2[i], nums1[i]});
    }
    sort(arr.begin(), arr.end(), comp);
    int i;
    for (i = 0; i < k - 1; i++)
    {
        pq.push(arr[i].second);
        sum += arr[i].second;
    }
    int ans = 0;
    ans = max(ans, (sum + arr[i].second) * arr[i].first);
    for (; i < arr.size() - 1; i++)
    {
        if (!pq.empty()&&  arr[i].second > pq.top())
        {
            sum = sum + arr[i].second - pq.top();
            pq.pop();
            pq.push(arr[i].second);
        }
        ans = max(ans, (sum + arr[i + 1].second) * arr[i + 1].first);
    }
    return ans;
}
int main()
{
    // vector<int> nums1={4,2,3,1,1},nums2={7,5,10,9,6};
    // vector<int> nums1={2,1,14,12},nums2={11,7,13,6};
    // vector<int> nums1={1,3,3,2},nums2={2,1,3,4};
    vector<int> nums1={23,16,20,7,3},nums2={19,21,22,22,12};
    // cout<<maxScore(nums1,nums2,1);
    cout<<maxScore(nums1,nums2,3);
}