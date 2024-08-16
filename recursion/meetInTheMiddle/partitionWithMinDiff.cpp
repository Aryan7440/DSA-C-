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
    int total = accumulate(nums.begin(), nums.end(), 0);
    for (int i = 0; i <= n; i++)
    {
        int k = n - i;
        sort(s1[i].begin(), s1[i].end());
        sort(s2[k].begin(), s2[k].end());
        int l = 0, r = s2[k].size() - 1;
        while (l < s1[i].size() && r >= 0)
        {
            int sum = s1[i][l] + s2[k][r];
            int sum2 = total - sum;
            int diff = abs(sum - sum2);
            ans = min(ans, diff);
            if (sum > total / 2)
                r--;
            else
                l++;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {2, -1, 0, 4, -2, -9};
    cout << minimumDifference(nums);
}