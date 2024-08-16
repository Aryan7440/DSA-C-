#include <bits/stdc++.h>
using namespace std;
string simplifyPath(string path)
{
    stack<string> s;
    int n = path.size();
    int l = 1, r = 1;
    while (r < n)
    {
        while (l < n && path[l] == '/')
        {
            l++;
        }
        r = l;
        string temp = "";
        while (r < n && path[r] != '/')
        {
            temp = temp + path[r++];
        }
        if ( !s.empty() && temp == "..")
            s.pop();
        else if (temp != "." && temp!="" && temp!="..")
            s.push(temp);
        l=r;
    }
    string ans="";
    while (!s.empty())
    {
        ans = s.top()+ans;
        ans="/"+ans;
        s.pop();
    }
    if(ans.empty())return "/";
    return ans;
}
int main()
{
    // string path="/home/";
    string path="/../";
    // string path="/a/./b/../../c/";
    cout<<simplifyPath(path);
}