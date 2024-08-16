#include <bits/stdc++.h>
using namespace std;
int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> set(wordList.begin(), wordList.end());
    if (!set.count(endWord))
        return 0;

    queue<string> q;
    q.push(beginWord);
    

    unordered_set<string> visited;
    visited.insert(beginWord);

    int ans = 0;
    while (!q.empty())
    {
        ans++;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            string s = q.front();
            q.pop();
            if (s == endWord)
                return ans;
            for (int j = 0; j < s.size(); j++)
            {
                string t = s;
                for (char c = 'a'; c <= 'z'; c++)
                {
                    t[j] = c;
                    if (set.count(t) && !visited.count(t))
                    {
                        q.push(t);
                        visited.insert(t);
                    }
                }
            }
        }
        // ans++;
    }
    return 0;
}

int main()
{
    string beginWord = "hot", endWord = "dog";
    vector<string> wordList = {"hot","dog"};
    cout<<ladderLength(beginWord,endWord,wordList);
}