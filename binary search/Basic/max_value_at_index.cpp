#include <bits/stdc++.h>
using namespace std;
bool check(int n, int index, int maxSum, int num)
{
    double sum = num;
    int li = index;
    int ri = n - index - 1;
    // li=min(li,num-1);
    if (li > num - 1)
    {
        sum += li - num + 1;
        li = min(li, num - 1);
    }
    if (ri > num - 1)
    {
        sum += ri - num + 1;
        ri = min(ri, num - 1);
    }
    // ri=min(ri,num-1);
    sum += ((double)li / 2) * (2 * num - li - 1);
    sum += ((double)ri / 2) * (2 * num - ri - 1);
    return sum <= maxSum;
}
int maxValue(int n, int index, int maxSum)
{
    int l = 1, r = maxSum;
    int mid = l + (r - l) / 2;
    int ans = 0;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (check(n, index, maxSum, mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ans;
}
int main()
{
    cout << maxValue(4, 0, 4);
    // cout << maxValue(4, 2, 6);
}