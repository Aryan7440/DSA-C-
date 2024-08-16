#include <bits/stdc++.h>
using namespace std;
string join(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<int> LPS(n, 0);
    int len = 0;
    int i = 1, j = 0;
    while (i < n)
    {
        if (s1[i] == s1[len])
        {
            len++;
            LPS[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = LPS[len - 1];
            else
            {
                LPS[i++] = 0;
            }
        }
    }
}