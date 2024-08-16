#include <bits/stdc++.h>
using namespace std;
int search(vector<int> &stones, int x, int start)
{
    int l = start, r = stones.size() - 1, n = stones.size();
    int mid = l + (r - l) / 2;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (stones[mid] == x)
            return mid;
        else if (stones[mid] > x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
bool help(vector<int> &stones, int ind, int k, unordered_map<int, unordered_map<int, int>> &dp)
{
    int n = stones.size();
    if (ind == n - 1)
        return true;
    if (ind == stones.size())
        return false;
    if (dp[ind].find(k) != dp[ind].end())
        return dp[ind][k];

    bool res = false;
    int l = search(stones, stones[ind] + (k - 1), ind + 1);
    if (k != 0 && l != -1)
        res = res || help(stones, l, k - 1, dp);
    int m = search(stones, stones[ind] + (k), ind + 1);
    if (k != 0 && m != -1)
        res = res || help(stones, m, k, dp);
    int r = search(stones, stones[ind] + (k + 1), ind + 1);
    if (r != -1)
        res = res || help(stones, r, k + 1, dp);
    return dp[ind][k] = res;
}
bool canCross(vector<int> &stones)
{
    unordered_map<int, unordered_map<int, int>> dp;
    return help(stones, 0, 0, dp);
}
int main()
{
    vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
    cout << canCross(stones);
}