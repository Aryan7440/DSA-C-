#include <bits/stdc++.h>
using namespace std;

long long find_sum(unordered_map<int, long long> &mp, int i, int j)
{
    if (i > j)
        return 0;
    else
        return mp[j] - mp[i - 1];
}
int maxFrequencyScore(vector<int> &nums, long long k)
{
    int i = 0, j = 0;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    unordered_map<int, long long> mp;
    mp[-1] = 0;
    for (int i = 0; i < n; i++)
        mp[i] = mp[i - 1] + nums[i];
    long long ans = INT_MIN;
    while (j < n)
    {
        long long medi = i + (j - i + 1) / 2;
        long long median = nums[medi];

        long long left = find_sum(mp, i, medi - 1);
        long long llen = max(0LL, (medi - i));
        long long lsum = median * llen - left;

        long long right = find_sum(mp, medi + 1, j);
        long long rlen = max(0LL, (j - medi));
        long long rsum = right - (median * rlen);

        long long len = j - i + 1;
        long long K = lsum + rsum;
        if (K <= k)
        {
            ans = max(ans, len);
            j++;
        }
        else
            i++;
        if (i > j)
            j = i;
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 4, 2, 6};
    cout << maxFrequencyScore(nums, 3);
}