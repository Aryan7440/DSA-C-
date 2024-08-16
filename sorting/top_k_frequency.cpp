#include <bits/stdc++.h>
using namespace std;
// static bool comp(pair<int, int> &a, pair<int, int> &b)
// {
//     return a.second > b.second;
// }
// vector<int> topKFrequent(vector<int> &nums, int k)
// {
//     unordered_map<int, int> mp;
//     for (auto i : nums)
//         mp[i]++;
//     vector<pair<int, int>> v;
//     for (auto it : mp)
//         v.push_back({it.first, it.second});
//     sort(v.begin(), v.end(), comp);
//     vector<int> ans;
//     for (int i = 0; i < k; i++)
//     {
//         ans.push_back(v[i].first);
//     }
//     return ans;
// }
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    int M = 0;
    for (auto i : nums)
    {
        mp[i]++;
        M = max(M, mp[i]);
    }
    unordered_map<int, vector<int>> freq;
    for (auto i : mp)
    {
        freq[i.second].push_back(i.first);
    }

    vector<int> ans;
    for (int i = M; i >0; i--)
    {
        if (freq.find(i) != freq.end())
        {
            for (int j = 0; j < freq[i].size() && ans.size() < k; j++)
            {
                ans.push_back(freq[i][j]);
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> ans = topKFrequent(nums, 2);
    for (auto i : ans)
        cout << i << " ";
}