#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isKthBitSet(int n, int k)
{
    k++;
    if (n & (1 << (k - 1)))
        return true;
    else
        return false;
}
int main()
{
    // your code goes here
    int t;
    // cin >> t;
    t=1;
    while (t--)
    {
        int n;
        // cin >> n;
        n=5;
        int q;
        // cin >> q;
        q=1;
        // vector<int> a;
        vector<int> a={1,2,4,3,2};
        // for (int i = 0; i < n; i++)
        // {
        //     int temp;
        //     cin >> temp;
        //     a.push_back(temp);
        // }
        
        int ans = 0;
        while (q--)
        {
            int k=1, l1=1, r1=3, l2=5, r2=5;
            // int k, l1, r1, l2, r2;
            // cin >> k;
            // cin >> l1;
            // cin >> r1;
            // cin >> l2;
            // cin >> r2;
            for (int i = l1; i <= r1; i++)
            {
                for (int j = l2; j <= r2; j++)
                {
                    int s = a[i] ^ a[j];
                    if (isKthBitSet(s, k))
                        ans++;
                }
            }
            cout << ans << endl;
        }
    }

    // cout<<isKthBitSet(6,2);

    return 0;
}
