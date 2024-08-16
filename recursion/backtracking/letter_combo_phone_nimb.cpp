#include <bits/stdc++.h>
using namespace std;

void lettercombo(unordered_map<char, string> mp, string digits, vector<string> &ans, string ds, int ind)
{
    if (ds.length() == digits.length())
    {
        ans.push_back(ds);
        return;
    }

    for (int j = 0; j < mp[digits[ind]].length(); j++)
    {
        string st = mp[digits[ind]];
        lettercombo(mp, digits, ans, ds + st[j], ind + 1);
    }
}
vector<string> letterCombinations(string digits)
{
    unordered_map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> ans;
    string ds;
    lettercombo(mp, digits, ans, ds, 0);
    return ans;
}

int main()
{
    string digits = "23";
    vector<string> ans = letterCombinations(digits);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}