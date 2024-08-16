#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        if (n % x != 0)
            cout << -1 << endl;
        else
        {
            cout << x << " ";
            for (int i = 2; i < n; i++)
            {
                if (i == x)
                {
                    int p = 2;
                    while ((n / x) % p)
                    {
                        p++;
                    }
                    x = x * p;
                    cout << x << " ";
                }
                else
                    cout << i << " ";
            }
            cout << 1 << endl;
        }
    }
}