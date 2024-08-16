#include <bits/stdc++.h>
using namespace std;
// unordered_map<int, int> parent;
// int find(int x)
// {
//     if (parent.find(x) == parent.end())
//     {
//         parent[x] = x;
//     }
//     if (parent[x] != x)
//     {
//         return parent[x] = find(parent[x]);
//     }
//     return x;
// }
// void join(int x, int y)
// {
//     int px = find(x), py = find(y);
//     if (px == py)
//         return;
//     parent[px] = py;
// }
// string smallestEquivalentString(string s1, string s2, string baseStr)
// {
//     int n = s1.size();
//     for (int i = 0; i < n; i++)
//     {
//         join((int)s1[i], (int)s2[i]);
//     }
//     unordered_map<char, set<char>> mp;
//     for (auto i : parent)
//     {
//         char u_par=(char)find(i.first);
//         char par=(char)i.first;
//         char child=(char)i.second;

//         mp[u_par].insert(par);
//         mp[u_par].insert(child);
//     }
//     string ans = "";
//     for (auto i : baseStr)
//     {
//         if(parent.find(i)==parent.end())
//         {
//             ans+=i;
//             continue;
//         }
//         ans += (char)*(mp[(char)find(i)].begin());
//     }
//     return ans;
// }

unordered_map<int, int> parent;
int find_(int x)
{
    if (parent.find(x) == parent.end())
    {
        parent[x] = x;
    }
    if (parent[x] != x)
    {
        return parent[x] = find_(parent[x]);
    }
    return x;
}
void join(int x, int y)
{
    int px = find_(x), py = find_(y);
    if (px == py)
        return;
    if(px>py)parent[px] = py;
    else parent[py]=px;
}
string smallestEquivalentString(string s1, string s2, string baseStr)
{
    int n = s1.size();
    for (int i = 0; i < n; i++)
    {
        join((int)s1[i], (int)s2[i]);
    }
    for (int i=0;i<baseStr.size();i++)
    {
        if(parent.find(baseStr[i])!=parent.end())
        {
            baseStr[i]=char(find_(baseStr[i]));
        }  
    }
    return baseStr;
}
int main()
{
    string s1 = "leetcode", s2 = "programs", baseStr = "sourcecode";
    cout << smallestEquivalentString(s1, s2, baseStr);
    // l=p
    // e=r=o=c=a=s
    // t=g
    // d=m



}
