
#include <bits/stdc++.h>
using namespace std;

void generateSubsetSums(vector<vector<int>> &result, vector<int> &nums, int start, int end)
{
    int n = end - start + 1;
    int totalSubsets = 1 << n; // Total number of subsets

    for (int mask = 0; mask < totalSubsets; ++mask)
    {
        int subsetSum = 0;
        int subsetSize = 0;

        for (int i = 0; i < n; ++i)
        {
            if (mask & (1 << i))
            {
                subsetSum += nums[start + i];
                subsetSize++;
            }
        }

        result[subsetSize].push_back(subsetSum);
    }
}
int minimumDifference(vector<int> &nums)
{
    int N = nums.size();
    int n = N / 2;
    vector<vector<int>> s1(n + 1), s2(n + 1);
    generateSubsetSums(s1, nums, 0, n - 1);
    generateSubsetSums(s2, nums, n, N - 1);
    int ans = INT_MAX;
    int ts = accumulate(nums.begin(), nums.end(), 0);
    for (int i = 0; i <= n; i++)
    {
        int k = n - i;
        for (auto ss1 : s1[i])
        {
            for (auto ss2 : s2[k])
            {
                int A = ss1 + ss2;
                int B = ts - A;
                ans = min(ans, abs(B - A));
            }
        }
    }
    return ans;
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    // int t = 1;
    // // cin >> t;
    // while (t--)
    // {
    //     solve();
    // }
    // return 0;
}