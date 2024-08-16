#include <bits/stdc++.h>
using namespace std;
string minRemoveToMakeValid(string s)
{
    int n = s.size();
    int l = 0, r = n - 1;
    while (l < r)
    {
        while (l < r && s[l] != '(')
        {
            if (s[l] == ')')
                s[l] = '#';
            l++;
        }

        while (l < r && s[r] != ')')
        {
            if (s[r] == '(')
                s[r] = '#';
            r--;
        }

        if (l < r && s[l] == '(' && s[r] == ')')
        {
            l++;
            r--;
        }
        if (l == r)
        {
            s[l] = '#';
            l++;
        }
    }
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '#')
            ans.push_back(s[i]);
    }
    return ans;
}
int main()
{
    string s = "lee(t(c)o)de)";

    cout << minRemoveToMakeValid(s);
    return 0;
}