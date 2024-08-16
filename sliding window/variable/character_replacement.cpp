#include <bits/stdc++.h>
using namespace std;


string characterReplacement(string s,int k)
{
    int len=0,max_f=INT_MIN;
    int i=0;
    int j=0;
    unordered_map<char,int> mp;
    string sub;
    while(j<s.size())
    {
        mp[s[j]]++;
        max_f=max(max_f,mp[s[j]]);
        while((j-i+1 - max_f)>k)
        {
            mp[s[i]]--;
            i++;
        }
        if(j-i+1>len)sub=s.substr(i,j-i+1);
        len=max(len,j-i+1);
        j++;
    }
    return sub;
    // return len;
}
int main()
{
    // string s = "ABBB";
    // string s = "ABAB";
    string s = "AAAAABBBBCBB";
    // string s = "BAAAB";
    // string s = "AABABBA";
    cout << characterReplacement(s, 4);
}