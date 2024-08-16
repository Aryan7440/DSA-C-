#include <bits/stdc++.h>
using namespace std;
double delta = 1e-8;
double sqrt_(long long n)
{
    double l = 0, r = max(1.0, (double)n);
    while (l + delta < r)
    {
        double mid = l + (r - l) / 2;
        if (mid * mid < n)
            l = mid;
        else
            r = mid;
    }
    return r;
}
int main()
{

    // cout << "Hello World";
    double n;
    cin >> n;
    cout << setprecision(7) << sqrt_(n);
    return 0;
}