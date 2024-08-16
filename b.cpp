#include <bits/stdc++.h>
using namespace std;
vector<int> factors(int n)
{
    vector<int> factors;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            if (i != n / i)
                factors.push_back(n / i);
        }
    }
    return factors;
}

int leastFactorGreaterThanB(int a, int b)
{
    vector<int> factors_a = factors(a);
    int ans = INT_MAX;
    for (int i = 0; i < factors_a.size(); i++)
    {
        if (factors_a[i] > b)
        {
            ans = min(ans, factors_a[i]);
        }
    }
    return ans;
}
int main()
{

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            cout << "NO" << endl;
            return 0;
        }
        else
        {
            a[i] = leastFactorGreaterThanB(a[i], a[i - 1]);
        }
    }
    cout << "YES" << endl;

    return 0;
}