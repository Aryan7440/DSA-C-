#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p)
{
    vector<int> mp(26, 0);
    vector<int> np(26, 0);
    int c = 0;
    for (auto i : p)
    {
        mp[i - 'a']++;
        if(mp[i-'a']==1)c++;
    }
    int count = 0;
    int i = 0, j = 0;
    vector<int> ans;
    while (j < s.size())
    {
        while (j < s.size() && j - i + 1 <= p.size())
        {
            np[s[j] - 'a']++;
            if (mp[s[j] - 'a'] &&np[s[j]-'a']==mp[s[j]-'a'])
                count++;
            if (count == c)
            {
                ans.push_back(i);
            }
            j++;
        }
        if(mp[s[i]-'a'] && np[s[i]-'a']==mp[s[i]-'a'] )count--;
        np[s[i] - 'a']--;
        
        i++;
    }
    return ans;
}

int main()
{
    string s = "abab", p = "ab";
    // string s = "cbaebabacd", p = "abc";
    vector<int> ans = findAnagrams(s, p);
    for (auto i : ans)
        cout << i << " ";
}