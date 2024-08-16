#include <bits/stdc++.h>
using namespace std;
int NthRoot(int n, int m)
{
    // Code here.
    int l = 1, r = m;
    int mid = l + (r - l) / 2;
    long long res = 1;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        res = 1;
        for (int i = 1; i <= n; i++)
        {
            res *= mid;
            if (res > m)
                break;
        }
        if (res > m)
            r = mid - 1;
        else if (res < m)
            l = mid + 1;
        else
            return mid;
    }
    return -1;
}
int main()
{
    cout<<NthRoot(9,1953125);
}