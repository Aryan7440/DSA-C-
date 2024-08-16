#include <bits/stdc++.h>
using namespace std;
bool checkInclusion(string s1, string s2)
{
    int i = 0, j = 0;
    vector<int> mp(26, 0);
    vector<int> dict(26, 0);
    int count = s1.size();
    for (auto l : s1)
    {
        mp[l - 'a']++;
    }
    while (j < s2.size())
    {
        dict[s2[j] - 'a']++;
        if (dict[s2[j] - 'a'] > mp[s2[j] - 'a'])
        {
            while (dict[s2[j] - 'a'] > mp[s2[j] - 'a'])
            {
                dict[s2[i] - 'a']--;
                i++;
            }
        }
        if (count == j - i + 1)
            return true;
        j++;
    }
    return false;
}
int main()
{
    string s1 = "adc", s2 = "dcda";
    // string s1 = "ab", s2 = "eidboaoo";
    // string s1 ="hello",s2 ="ooolleoooleh";
    // string s1 = "ab", s2 = "eidbaooo";
    cout << checkInclusion(s1, s2);
}