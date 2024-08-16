#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
vector<vector<long long>> comb(int N)
{
    vector<vector<long long>>nCr(N + 1);
    for (int i = 0; i < N + 1; ++i)
    {
        nCr[i] = vector<long long>(i + 1, 1);
        for (int j = 1; j < i; ++j)
        {
            nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % mod;
        }
    }
    return nCr;
}
int util(vector<int> &nums, vector<vector<long long>> &nCr)
{
    int n = nums.size();
    if (n <= 2)
        return 1;
    vector<int> left, right;
    for (int i = 1; i < n; i++)
    {
        if (nums[0] > nums[i])
            left.push_back(nums[i]);
        else
            right.push_back(nums[i]);
    }
    int r = left.size();
    return ((nCr[n - 1][r] % mod) * (util(left, nCr) % mod) * (util(right, nCr) % mod)) % mod;
}

int numOfWays(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<long long>> nCr = comb(n);
    return util(nums, nCr) % mod - 1;
}

int main()
{
    vector<int> nums = {2, 1, 3};
    cout << numOfWays(nums);
}