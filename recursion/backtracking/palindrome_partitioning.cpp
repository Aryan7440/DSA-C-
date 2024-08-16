#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(string s,int start,int stop)
{
    while (start <= stop)
    {
        if (s[start++] != s[stop--])
        {
            return false;
        }
    }
    return true;
}

void partition(int index, string s, vector<string> ds, vector<vector<string>> &ans)
{
    if (index == s.size())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = index; i < s.size(); i++)
    {
        if (is_palindrome(s,index,i))
        {
            ds.push_back(s.substr(index,i-index+1));
            partition(i+1,s,ds,ans);
            ds.pop_back();
        }
    }
}

vector<vector<string>> palindrome_partitioning(string s)
{
    vector<vector<string>> ans;
    vector<string> ds;
    partition(0, s, ds, ans);

    return ans;
}

int main()
{
    // string s = "aadadaak";
    // cout << is_palindrome(s.substr(2, 3));

    string s = "aabb";
    vector<vector<string>> ans = palindrome_partitioning(s);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << endl;
        }
        cout << "---------------------------------------" << endl;
    }
}