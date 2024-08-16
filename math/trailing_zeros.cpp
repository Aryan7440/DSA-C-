#include <bits/stdc++.h>
using namespace std;
int trailingZeroes(int n)
{
    int sum = 0;
    for (int i = 5; n / i >= 1; i *= 5)
    {
        sum += n / i;
    }
    return sum;
}
int main()
{
    cout << trailingZeroes(100);
}