#include <bits/stdc++.h>
using namespace std;
string normalise(string w)
{
    unordered_map<char, char> mp;
    char c = '1';
    for(auto ch:w)
    {
        if(!mp.count(ch))
        {
            mp[ch]=c++;
        }
    }
    for(int i=0;i<w.size();i++)
    {
        w[i]=mp[w[i]];
    }
    return w;
}
vector<string> findAndReplacePattern(vector<string> &words, string &pattern)
{
    vector<string> ans;
    string p = normalise(pattern);
    for (auto &w : words)
        if (p == normalise(w))
            ans.push_back(w);
    return ans;
}

int main()
{
    string s = "xyzaakkll";
    cout << normalise(s);
    // for(auto ch:s)
    // {
    //     cout<<ch<<" ";
    // }
}