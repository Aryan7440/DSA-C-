#include <bits/stdc++.h>
using namespace std;
int util(vector<string> &arr, vector<int> &mask, int ind, int Mask)
{
    if (ind >= arr.size())
        return 0;
    int take = 0;
    if (mask[ind] != -1 && (Mask & mask[ind]) == 0)
        take = arr[ind].size() + util(arr, mask, ind + 1, Mask | mask[ind]);
    int not_take = util(arr, mask, ind + 1, Mask);
    return max(take, not_take);
}
int maxLength(vector<string> &arr)
{
    int n = arr.size();
    vector<int> mask;
    for (auto str : arr)
    {
        int m = 0;
        for (auto c : str)
        {
            long long bit = 1 << (c - 'a');
            if ((bit & m) != 0)
            {
                m = -1;
                break;
            }
            m = m | bit;
        }
        mask.push_back(m);
    }
    return util(arr, mask, 0, 0);
}
int main()
{
    // vector<string> arr = {"cha", "r", "act", "ers"};
    vector<string> arr = {"aa", "bb"};
    cout << maxLength(arr);
    // cout << (1 << ('r' - 'a'));
}