#include <bits/stdc++.h>
using namespace std;
vector<int> compute_LPS(string s)
{
    vector<int> LPS(s.size(), 0);
    LPS[0] = 0;         // length of first element is always zero
    int i = 1, len = 0; // i for pattern and len for lps(length of previous longesr suffix that is also a prefix)
    while (i < s.size())
    {
        if (s[i] == s[len])
        {
            len++;
            LPS[i] = len;
            i++;
        }
        else // (s[i] != s[len])
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
string longest_palidromic_substring(string pat)
{
    vector<int> LPS = compute_LPS(pat);
    string text;
    for (int i = pat.size() - 1; i >= 0; i--)
        text.push_back(pat[i]);
    int i = 0, j = 0;
    int ans;
    while (i < text.size())
    {
        if (text[i] == pat[j])
        {
            i++;
            j++;
            ans=j;
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
    string res = pat.substr(ans, pat.size() - ans) + pat;
    return res;
}
string shortestPalindrome(string s)
{
    vector<int> LPS = compute_LPS(s);
    string text;
    for (int i = s.size() - 1; i >= 0; i--)
        text.push_back(s[i]);
    int i = 0, j = 0;
    int ans;
    int m = 0;
    while (i < text.size())
    {
        if (text[i] == s[j])
        {
            i++;
            j++;
            if (j > m)
            {
                ans = j;
                m = j;
            }
        }
        else if (i < text.size() && text[i] != s[j])
        {
            if (j != 0)
            {
                j = LPS[j - 1];
            }
            else
                i++;
        }
    }
    string res = s.substr(ans, s.size() - ans);
    reverse(res.begin(), res.end());

    return res + s;
}
int main()
{
    string s = "ababbbabbaba";
    // string s = "pepcoding";
    cout<<longest_palidromic_substring(s);
    // cout << shortestPalindrome(s);
}