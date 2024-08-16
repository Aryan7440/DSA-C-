#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &A)
{
    sort(A.begin(), A.end());
    int n = A.size();
    // unordered_map<int,int> mp;

    for (int i = 0; i < n; i++)
    {
        int num = A[i];
        int l = i, r = n;
        while (l + 1 < r)
        {
            int mid = l + (r - l) / 2;
            if (A[mid] <= num)
                l = mid;
            else
                r = mid;
        }
        int count = n - r;
        if (A[i] == count)
            return 1;
    }
    return -1;
}

int main()
{
    vector<int> arr = {5, 6, 7};
    cout << solve(arr) << endl;
    return 0;
}