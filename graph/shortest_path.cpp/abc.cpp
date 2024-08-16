#include <bits/stdc++.h>
using namespace std;

int minimumPushes(string word)
{
    // unordered_map<char,unordered_set<int>>mp;
    vector<int> freq(26, 0);
    for (auto i : word)
    {
        freq[i - 'a']++;
    }
    sort(freq.begin(), freq.end());
    int count = 0;
    int mul = 1;
    int flag = 0;
    for (int i = 25; i >= 0; i = i - 8)
    {
        for (int j = i; j >= 0 && j > i - 8; j--)
        {
            count += freq[j] * mul;
            if (freq[j] == 0)
                flag = 1;
        }
        if (flag)
            break;
        mul++;
    }
    return count;
}
int main()
{
    // int n = 4, x = 1, y = 1;
    // int n = 5, x = 2, y = 4;
    // vector<int> ans = countOfPairs(n, x, y);
    // for (auto i : ans)
    //     cout << i << " ";
    string s = "bvyfdneojulitxzhkaswgrmc";
    cout << minimumPushes(s);

    return 0;
}