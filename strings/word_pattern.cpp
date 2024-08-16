#include <bits/stdc++.h>
using namespace std;
string normalise(string &word)
{
    unordered_map<char, char> mp;
    char c = 'a';
    for (auto i : word)
    {
        if (!mp[i])
        {
            mp[i] = c++;
        }
        word[i] = mp[i];
    }
    return word;
}

string normalise_(string s)
{
    istringstream ss(s);
    string word;
    unordered_map<string, char> mp;
    char c = 'a';
    string ans;
    while (ss >> word)
    {
        if (!mp[word])
        {
            mp[word] = c++;
        }
        ans.push_back(mp[word]);
    }
    return ans;
}
bool wordPattern(string pattern, string s)
{
    vector<string> words;
    istringstream ss(s);
    string word;
    while (ss >> word)
    {
        words.push_back(word);
    }
    if (words.size() != pattern.size())
        return false;
    unordered_map<string, char> stc;
    unordered_map<char, string> ctc;
    for (int i = 0; i < words.size(); i++)
    {
        if (stc.find(words[i])==stc.end() && ctc.find(pattern[i])==ctc.end())
        {
            stc[words[i]] = pattern[i];
            ctc[pattern[i]] = words[i];
        }
        else if(stc[words[i]]!=pattern[i])return false;
    }
    return true;
}

int main()
{
    string pattern = "abba";
    string s = "dog cat cat dog";
    cout << wordPattern(pattern, s);
}