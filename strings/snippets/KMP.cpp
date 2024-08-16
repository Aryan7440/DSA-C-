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
vector<int> KMP(string text, string pat)
{
    vector<int> LPS = compute_LPS(pat);
    vector<int> ans;
    int i = 0, j = 0;
    while (i < text.size())
    {
        if (text[i] == pat[j])
        {
            i++;
            j++;
            if (j == pat.size())
                ans.push_back(i + 1 - pat.size());
        }
        else if (i < text.size() && text[i] != pat[j])
        {
            if (j != 0)
            {
                j = LPS[j - 1];
            }
            else
                i++;
        }
    }
    return ans;
}
int main()
{
    // vector<int>ans=compute_LPS("AAACAAAA");
    string text = "ab", pat = "ABCABCMABCD";
    vector<int> lps1 = compute_LPS(pat);
    for (auto i : lps1)
        cout << i << " ";

    // vector<int> ans=KMP(text,pat);
    // for(auto i:ans)cout<<i<<" ";
}