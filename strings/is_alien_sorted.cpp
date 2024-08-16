#include <bits/stdc++.h>
using namespace std;
bool isAlienSorted(vector<string> &words, string order)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < order.size(); i++)
        mp[order[i]] = i;
    int k = 0;
    while (k < words.size() - 1)
    {
        int i = 0, j = 0;
        while (i < words[k].size() && j < words[k + 1].size())
        {
            if (mp[words[k][i]] > mp[words[k + 1][j]])
            {
                return false;
            }
            else if (mp[words[k][i]] == mp[words[k + 1][j]])
            {
                i++;
                j++;
                continue;
            }
            else
                break;
        }

        k++;
    }
    return true;
}
int main()
{
    vector<string> words = {"hello", "leetcode"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    cout << isAlienSorted(words, order);
}