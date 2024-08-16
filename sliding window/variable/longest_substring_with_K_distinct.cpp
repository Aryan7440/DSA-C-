#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
int getLengthofLongestSubstring(string s, int k) {
    unordered_map <char,int> mp;
    int i=0,j=0;
    int count=0;
    while(j<s.size())
    {
        mp[s[j]]++;
        if(mp.size()<=k)
        {
            count=max(j-i+1,count);
        }
        
        else if(mp.size()>k)
        {
            while(mp.size()>k)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
        }
        j++;
    }
    return count;
}

int main()
{
    string s="iccjr";
    cout<<getLengthofLongestSubstring(s,2);
}