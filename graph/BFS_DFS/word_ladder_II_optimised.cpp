#include <bits/stdc++.h>
using namespace std;
void backtrack(unordered_map<string, int> &mp, vector<string> &wordList, string beginWord, string word, vector < vector<string>> & ans,vector<string> &ds)
{
    if(word==beginWord)
    {
        reverse(ds.begin(),ds.end());
        ans.push_back(ds);
        reverse(ds.begin(),ds.end());
        return;
    }
    string o=word;
    for(int i=0;i<word.size();i++)
    {
        char org=word[i];
        for(int c='a';c<='z';c++)
        {
            word[i]=c;
            if(mp.find(word)!=mp.end() && mp[word]+1==mp[o])
            {
                ds.push_back(word);
                backtrack(mp,wordList,beginWord,word,ans,ds);
                ds.pop_back();
            }
        }
        word[i]=org;
    }
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> set(wordList.begin(), wordList.end());
    unordered_map<string, int> mp;
    queue<string> q;
    q.push(beginWord);
    set.erase(beginWord);
    int flag = 0;
    int level = 1;
    mp[beginWord] = level;
    while (!q.empty())
    {
        int n = q.size();
        level++;
        for (int i = 0; i < n; i++)
        {
            string s = q.front();
            // mp[s]=level;
            q.pop();
            for (int j = 0; j < s.size(); j++)
            {
                char org = s[j];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    s[j] = c;
                    if (set.find(s) != set.end())
                    {
                        set.erase(s);
                        q.push(s);
                        mp[s] = level;
                        if (s == endWord)
                        {
                            flag = 1;
                            break;
                        }
                    }
                }
                if (flag)
                    break;
                s[j] = org;
            }
            if (flag)
                break;
        }
        if (flag)
            break;
    }
    vector<vector<string>> ans;
    vector<string> ds;
    if (mp.find(endWord) != mp.end())
    {
        ds.push_back(endWord);
        backtrack(mp, wordList, beginWord, endWord, ans,ds);
    }
    return ans;
}
int main()
{
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> ans = findLadders(beginWord, endWord, wordList);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << "  ";
        cout << endl;
    }
}