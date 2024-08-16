#include <bits/stdc++.h>
using namespace std;

void parenthesis(int o, int c, vector<string> &ans, string s)
{
    // if (o == 0 && c == 0)
    // {
    //     ans.push_back(s);
    //     return;
    // }
    // if (o != 0)
    // {
    //     // s.push_back('(');
    //     parenthesis(o - 1, c, ans, s + '(');
    // }
    // if (c > o)
    // {
    //     // s.push_back(')');
    //     parenthesis(o, c - 1, ans, s + ')');
    // }

    if(o==0  && c==0)
    {
        ans.push_back(s);
        return;
    }
    if (o!=0)
    {
        parenthesis(o-1,c,ans,s+'(');
        // parenthesis(o,c-1,ans,s+')');
    }
    if(o<c)
    {
        parenthesis(o,c-1,ans,s+')');
    }
    
}

vector<string> parenth(int n)
{
    vector<string> ans;
    string s;
    parenthesis(n, n, ans, s);
    return ans;
}

int main()
{
    vector<string> ans = parenth(5);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}