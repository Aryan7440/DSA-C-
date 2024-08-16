#include <bits/stdc++.h>
using namespace std;
int bestClosingTime(string customers)
{
    int n = customers.size();
    vector<int> s1(n, 0), s2(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (customers[i] == 'N')
            sum++;
        s1[i] = sum;
    }

    sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (customers[i] == 'Y')
            sum++;
        s2[i] = sum;
    }
    int pen = s2[0];
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (pen > s1[i] + s2[i + 1])
        {
            pen = s1[i] + s2[i + 1];
            ans = i+1;
        }
    }
    if (pen > s1[n - 1])
    {
        pen = s1[n - 1];
        ans = n ;
    }
    return ans;
}
int main()
{
    string customers="YYNY";
    cout<<bestClosingTime(customers);
}