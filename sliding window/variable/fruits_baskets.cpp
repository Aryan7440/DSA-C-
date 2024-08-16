#include <unordered_map>
using namespace std;
#include <bits/stdc++.h>
int findMaxFruits(string &str, int n) {
    int i=0,j=0;
    int count=INT_MIN;
    unordered_map<char,int>mp;
    while(j<n)
    {
        mp[str[j]]++;
        if(mp.size()>2)
        {
            
            while(mp.size()>2)
            {
                mp[str[i]]--;
                if(mp[str[i]]==0)
                {
                    mp.erase(str[i]);
                }
                i++;
            }
        }
        count=max(count,j-i+1);
        j++;
    }
    return count;
}
int main()
{
    string s="EDAECECACC";
    cout<<findMaxFruits(s,s.size());
}
