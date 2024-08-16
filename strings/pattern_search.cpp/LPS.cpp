#include <bits/stdc++.h>
using namespace std;
vector<int> compute_LPS(string pat)
{
    vector<int> LPS(pat.size(), 0);
    LPS[0] = 0;         // length of first element is always zero
    int i = 1, len = 0; // i for pattern and len for lps(length of previous longesr suffix that is also a prefix)
    while (i < pat.size())
    {
        if (pat[i] == pat[len])
        {
            len++;
            LPS[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0)
            {
                len = LPS[len - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                LPS[i] = 0;
                i++;
            }
        }
    }
    return LPS;
}
int main()
{
    string pat = "abaababaab";
    // string pat = "abcabcabcabc";
    // string pat = "ababbbabbabaababbabbbaba";
    // string pat = "aacecaaa";
    vector<int> LPS = compute_LPS(pat);
    for (int i = 0; i < pat.size(); i++)
    {
        cout<<pat[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < pat.size(); i++)
    {
        cout<<LPS[i]<<" ";
    }
    cout<<endl;
}