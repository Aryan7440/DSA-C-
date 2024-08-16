#include <bits/stdc++.h>
using namespace std;
void dfs(unordered_set<string> &mp, string &s,vector<string> &strs)
{
    mp.erase(s);

    for (auto &i : strs)
    {
        if(i=="")continue;
        int count = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (i[j] != s[j])
            {
                count++;
                if (count > 2)
                    break;
            }
        }
        if (count == 2)
        {
            string st=i;
            i="";
            dfs(mp, st,strs);
        }
    }
}
int numSimilarGroups(vector<string> &strs)
{
    // vector<int> vis(strs.size(),0);
    unordered_set<string> mp(strs.begin(), strs.end());
    int grp = 0;
    for (int i = 0; i < strs.size(); i++)
    {
        if (mp.find(strs[i]) != mp.end())
        {
            grp++;
            string str=strs[i];
            strs[i]="";
            dfs(mp, str,strs);
        }
    }
    return grp;
}
int main()
{
    vector<string> strs={"tars","rats","arts","star"};
    cout<<numSimilarGroups(strs);
}