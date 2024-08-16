#include<bits/stdc++.h>
using namespace std;

int count(string s,string p)
{
    unordered_map <char,int> freq;
    for(auto i:p)
    {
        freq[i]++;
    }
    int i=0,j=0;
    int count=freq.size();
    int ans=0;
    
    while(j<s.size())
    {
        if(freq.find(s[j])!=freq.end())
        {
            freq[s[j]]--;
            if(freq[s[j]]==0)
            {
                count--;
            }
        }
        if(j-i+1 < p.size())
        {
            j++;
        }
        else if(j-i+1 ==p.size())
        {
            if(count==0)
            {
                ans++;
            }
            if(freq.find(s[i])!=freq.end())
            {
                freq[s[i]]++;
                if(freq[s[i]]==1)
                {
                    count++;
                }
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    string s="aabaabaa";
    string p="aaba";
    cout<<count(s,p);
}