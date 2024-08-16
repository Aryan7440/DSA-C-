#include <bits/stdc++.h>
using namespace std;

bool isvalid(string s, unordered_map<char, int> mp)
{
    for (auto i : s)
    {
        if (mp.count(i)!=0)
        {
            mp[i]--;
            if (mp[i] == 0)
            {
                mp.erase(i);
            }
        }
    }
    return mp.empty();
}

vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
{
    unordered_map<char,int> mp;
    vector<string> ans;
    for(auto i:words2)
    {
        mp[i[0]]++;
    }
    for(auto i:words1)
    {
        if(isvalid(i,mp))
        {
            ans.push_back(i);
        }
    }
    return ans;
}

// ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]

int main()
{
    // vector<string> w1={"amazon","apple","facebook","google","leetcode"};
    // vector<string> w2={"e","o"};
    // vector<string> s=wordSubsets(w1,w2);
    // for(auto i:s)
    // {
    //     cout<<i<<endl;
    // }

    string s="aryanshukla";
    cout<<s.substr(1,4);
}