#include <bits/stdc++.h>
using namespace std;

string rev(string s)
{
    for (int i = 0; i < s.size() / 2; i++)
    {
        swap(s[i], s[s.size() - 1]);
    }
    return s;
}
string reverseWords(string s)
{
    string ans = "";
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
            continue;
        else
        {
            int j = i;
            while (j>=0 && s[j] != ' ')
                j--;
            string st = s.substr(j + 1, i - j);
            ans += st + " ";
            i = j;
        }
    }
    if (ans[ans.size() - 1] == ' ')
        ans.pop_back();
    return ans;
}
int main()
{
    string s="MY NAME IS ARYAN SHUKLA ";
    string ans=reverseWords(s);
    cout<<ans;
}