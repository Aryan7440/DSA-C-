#include <bits/stdc++.h>
using namespace std;
string mergeStrings(string s1, string s2)
{
    int len1 = s1.size();
    int len2 = s2.size();
    int p1 = len1 - 1;
    ;
    int p2 = 0;
    string ans = "";
    while (s1[p1] == s2[p2])
    {
        p1--;
        p2++;
    }
    ans = s1.substr(0, p1 + 1);
    ans = ans + s2;
    return ans;
}
string help(string a, string b, string c)
{
    string str = mergeStrings(a, b);
    string ans = mergeStrings(str, c);
    return ans;
}
string minimumString(string a, string b, string c)
{
    vector<string> ans;
    ans.push_back(help(a, b, c));
    ans.push_back(help(a, c, b));
    ans.push_back(help(b, a, c));
    ans.push_back(help(b, c, a));
    ans.push_back(help(c, b, a));
    ans.push_back(help(c, a, b));
    sort(ans.begin(), ans.end());
    return ans[0];
}
int main()
{
    string a = "abc",b = "bca",c = "aaa";
    cout<<minimumString(a,b,c);
}