#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> set(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    vector<string> vec;
    vec.push_back(beginWord);
    set.erase(beginWord);
    q.push(vec);
    int flag = 0;
    vector<vector<string>> ans;
    while (!q.empty())
    {
        int n = q.size();
        vector<string> wordused;
        for (int i = 0; i < n; i++)
        {
            vector<string> temp = q.front();
            q.pop();
            string s = temp.back();
            for (int j = 0; j < s.size(); j++)
            {
                char org = s[j];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    s[j] = c;
                    if (set.find(s) != set.end())
                    {
                        temp.push_back(s);
                        wordused.push_back(s);
                        q.push(temp);
                        if (s == endWord)
                        {
                            flag = 1;
                            ans.push_back(temp);
                        }
                        temp.pop_back();
                    }
                }
                s[j] = org;
            }
        }
        for (auto i : wordused)
            set.erase(i);
        wordused.clear();
        if (flag)
            break;
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