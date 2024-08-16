#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s)
{
    int i = 0, j = 0, count = 0, flag = 0;
    unordered_map<char, int> mp;
    mp['a'] = 0;
    mp['b'] = 0;
    mp['c'] = 0;

    while (j < s.size())
    {
        mp[s[j]]++;
        while (mp['a'] && mp['b'] && mp['c'])
        {
            count+=s.size()-j;
            mp[s[i]]--;
            i++;
        }
        // count += i;
        j++;
    }
    return count;
}
int main()
{
    string s="abcabc";
    cout<<numberOfSubstrings(s);
}