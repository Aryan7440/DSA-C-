#include <bits/stdc++.h>
using namespace std;
int ub(vector<int> &arr, int x)
{
    int l = -1, r = arr.size();
    while (l + 1 < r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] > x)
            r = mid;
        else
            l = mid;
    }
    return r;
}
void solve()
{
    string A, B;
    cin >> A;
    cin >> B;
    // unordered_map<char, vector<int>> mp;
    vector<vector<int>> mp(26);
    for (int i = 0; i < B.size(); i++)
    {
        mp[B[i] - 'A'].push_back(i);
    }
    int a = 0;
    int count = 0;
    while (a < A.size())
    {
        int l = a, r = -1;
        if (mp[A[l] - 'A'].size() == 0)
        {
            count = -1;
            break;
        }
        r = mp[A[l] - 'A'][0];
        while (l < A.size() && r < B.size())
        {
            l++;
            if (l == A.size() || mp[A[l] - 'A'].size() == 0)
                break;
            int next = ub(mp[A[l] - 'A'], r);
            if (next == mp[A[l] - 'A'].size())
                r = B.size();
            else
                r = mp[A[l] - 'A'][next];
        }
        a = l;
        count++;
    }
    cout << count << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}