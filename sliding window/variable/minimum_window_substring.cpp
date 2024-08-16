#include <bits/stdc++.h>
using namespace std;

// string minWindow(string s,string t)
// {
//     unordered_map<char, int> mp;
//     for (auto i : t)
//     {
//         mp[i]++;
//     }
//     unordered_map<char, int> win;
//     int l = 0, r = 0;

//     string ans;
//     int min_len = INT_MAX;
//     int len = 0;
//     int l_count = 0;
//     while(r<s.size())
//     {
//         win[s[r]]++;
//         if(mp.find(s[r])!=mp.end())
//         {
//             if(win[s[r]]<=mp[s[r]])l_count++;
//         }
//         if(l_count==t.size())
//         {

//             while (mp.find(s[l])==mp.end() || win[s[l]]>mp[s[l]])
//             {
//                 win[s[l]]--;
//                 l++;
//             }
//             // min_len=min(min_len,r-l+1);
//             if(r-l+1<min_len)
//             {
//                 ans=s.substr(l,r-l+1);
//                 min_len=r-l+1;
//             }
//         }
//         r++;
//     }
//     return ans;
// }

// string minWindow(string s, string t)
// {
//     unordered_map<char, int> om;
//     for (auto i : t)
//     {
//         om[i]++;
//     }
//     unordered_map<char, int> win;
//     int l = 0, r = 0;
//     string ans;
//     int min_len = INT_MAX;
//     int len = 0;
//     int l_count = 0;
//     while (r < s.size())
//     {
//         if (om.find(s[r]) != om.end())
//         {
//             win[s[r]]++;
//             if (win[s[r]] <= om[s[r]])
//                 l_count++;
//         }
//         if (l_count >= t.size())
//         {
//             while(om.find(s[l])==om.end() || win[s[l]]>om[s[l]])
//             {
//                 win[s[l]]--;
//                 l++;
//             }
//             len = r - l + 1;
//             if (len < min_len)
//             {
//                 min_len=len;
//                 ans=s.substr(l,len);
//             }

//         }
//         r++;
//     }
//     return ans;
// }
string minWindow(string s, string t)
{
    int n = s.size();
    int m = t.size();
    int l = 0, r = 0;
    unordered_map<char, int> mt, ms;
    for (auto c : t)
        mt[c]++;
    int count = 0;
    int ans = INT_MAX;
    string str;
    while (r < n)
    {
        while (r < n && count < mt.size())
        {
            if (mt.find(s[r]) != mt.end())
            {
                ms[s[r]]++;
                if (ms[s[r]] == mt[s[r]])
                {
                    count++;
                }
            }
            r++;
        }
        // ans=min(ans,r-l+1);
        while (l < n && count == mt.size())
        {
            if (ms.find(s[l]) != ms.end())
            {
                ms[s[l]]--;
                ms[s[l]] = max(ms[s[l]], 0);
                if (ms[s[l]] < mt[s[l]])
                {
                    // count--;
                    break;
                }
            }
            l++;
        }
        if (count == mt.size() && ans >= r - l)
        {
            ans = min(ans, r - l);
            str = s.substr(l, r - l);
        }
        l++;
        count--;
    }
    return str;
}
int main()
{
    string s = "ADOBECODEBANC", t = "ABC";
    cout << minWindow(s, t);
}