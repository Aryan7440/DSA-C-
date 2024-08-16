#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        unordered_set<int> st;
        int min_val = INT_MIN, max_val = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int a, k;
            cin >> a >> k;
            if (a == 1)
            {
                min_val = max(k, min_val);
            }
            else if (a == 2)
            {
                max_val = min(k, max_val);
            }
            else
                st.insert(k);
        }
        int count = max(0, max_val - min_val + 1);
        for (auto i : st)
        {
            if (i >= min_val && i <= max_val)
                count--;
        }
        cout << count << endl;
    }
}