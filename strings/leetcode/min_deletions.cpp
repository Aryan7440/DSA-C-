#include <bits/stdc++.h>
using namespace std;
int minDeletions(string s)
{
    vector<int> freq(26, 0);

    for (int i = 0; i < s.size(); i++)
        freq[s[i] - 'a'] += 1;
    sort(freq.begin(), freq.end(), greater<int>());
    int count = 0;
    int i = 0;
    while (i < freq.size())
    {
        int k = i;
        while (k < freq.size() && freq[k] == freq[i - 1])
        {
            freq[k]--;
            count++;
            k++;
        }
        if (freq[i] == 0)
            break;
        i++;
    }
    return count;
}
int main()
{
    string a="ceabaacb";
    // string a="aab";
    // string a="aaabbbcc";
    // string a="abcabc";
    cout<<minDeletions(a);
}