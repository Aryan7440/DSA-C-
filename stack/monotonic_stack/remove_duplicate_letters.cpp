#include <bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string s)
{
    string st;
    unordered_map<char, int> mp;
    unordered_map<char, int> vis;
    for (auto c : s)
    {
        mp[c]++;
        vis[c] = 0;
    }

    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (st.empty() || st.back() < s[i] && !vis[s[i]])
        {
            st.push_back(s[i]);
            vis[s[i]] = 1;
        }
        else
        {
            while (!st.empty() && st.back() > s[i] && mp[st.back()] > 0)
            {
                vis[st.back()] = 0;
                st.pop_back();
            }
            if (!vis[s[i]])
            {
                vis[s[i]] = 1;
                st.push_back(s[i]);
            }
        }
        mp[s[i]]--;
    }
    return st;
}
int main()
{
    string s = "bbcaac";
    // string s = "cbacdcbc";
    cout << removeDuplicateLetters(s);
}