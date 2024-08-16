#include <bits/stdc++.h>
using namespace std;
int longestValidSubstring(string word, vector<string> &forbidden)
{
    unordered_set<string> st;
    for (auto i : forbidden)
    {
        string s = i;
        reverse(s.begin(),s.end());
        st.insert(s);
    }
    int n = word.size();
    int l = 0, r = 0;
    int ans = 0;
    while (r < n)
    {
        string s;
        for (int i = r; i >= 0 && i >= r - 10 && i>=l; i--)
        {
            s.push_back(word[i]);
            if (st.find(s) != st.end())
            {
                l = i + 1;
                break;
            }
        }
        ans = max(ans, r - l + 1);
        r++;
    }
    return ans;
}
int main()
{
    string word = "aaaabaaacc";
    // string word = "acbc";
    vector<string> forbidden = {"bcca","aaa","aabaa","baaac"};
    cout<<longestValidSubstring(word,forbidden);
}