#include <bits/stdc++.h>
using namespace std;
int minInsertions(string s)
{
    int n = s.size();
    reverse(s.begin(), s.end());
    string p = s;
    reverse(s.begin(), s.end());
    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == p[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
            {
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
    }
    return n - curr[n];
}
int main()
{
    string s="zzazz";
    cout<<minInsertions(s);
}