#include <bits/stdc++.h>
using namespace std;
long long find(long long num, int x)
{
    long long count = 0;
    long long div = pow(2, x - 1);
    long long mul = pow(2, x);

    while (num + 1 > div)
    {
        long long grp = (num + 1) / div;
        long long rem = (num + 1) % div;
        long long ans = (grp / 2) * div;
        if (grp % 2 != 0)
            ans += rem;
        count += ans;
        div = div * mul;
    }
    return count;
}
long long binary(long long m, int x)
{
    long long l = 0, r = 1e16;
    long long mid = l + (r - l) / 2;
    long long res = -1;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        long long num = mid;
        long long count = find(num, x);
        if (count > m)
            r = mid - 1;
        else
        {
            res = num;
            l = mid + 1;
        }
    }
    return res;
}
long long findMaximumNumber(long long k, int x)
{
    long long ans = binary(k, x);
    return ans;
}
int countSetBits(int num)
{
    int count = 0;
    while (num)
    {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

// Function to calculate the total set bits from 1 to n
int totalSetBitsInRange(int n)
{
    int totalSetBits = 0;

    // Iterate through numbers from 1 to n
    for (int i = 1; i <= n; ++i)
    {
        totalSetBits += countSetBits(i);
    }

    return totalSetBits;
}
int main()
{
    // cout << findMaximumNumber(83, 1);
    // cout << find(4, 1);
    // cout << find(3278539330613, 5);
    for (int i = 0; i < 100; i++)
    {
        cout << find(i, 1) << " " << totalSetBitsInRange(i) << "\n";
    }
}
