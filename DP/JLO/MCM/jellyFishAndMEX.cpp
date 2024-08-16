#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> calculateMEX(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> mex(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        vector<int> freq(n + 1, 0);
        for (int j = i; j < n; j++)
        {
            freq[nums[j]]++;
            for (int k = 1; k <= n; k++)
            {
                if (freq[k] == 0)
                {
                    mex[i][j] = k;
                    break;
                }
            }
        }
    }
}