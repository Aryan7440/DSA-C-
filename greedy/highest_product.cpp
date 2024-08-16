#include <bits/stdc++.h>
using namespace std;

int highest_product(vector<int> &v)
{
    int r1, r2, r3;
    r1 = r2 = r3 = INT32_MIN;

    int l1, l2;
    l1 = l2 = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > 0)
        {
            if (v[i] > r1)
            {
                r3 = r2;
                r2 = r1;
                r1 = v[i];
            }
            else if (v[i] > r2)
            {
                r3 = r2;
                r2 = v[i];
            }
            else if (v[i] > r3)
            {
                r3 = v[i];
            }
        }
        else
        {
            if (v[i] < l1)
            {
                l2 = l1;
                l1 = v[i];
            }
            else if (v[i] < l2)
                l2 = v[i];
        }
    }

    int s1 = r1 * r2 * r3;
    int s2 = l1 * l2 * r1;
    return max(s1, s2);
}

int main()
{
    vector<int> v = {-1, -5, -3, 2};
    cout << highest_product(v) << endl;
}