#include <bits/stdc++.h>
using namespace std;

// int lengthOfLongestSubstring(string s)
// {
//     vector<int> set(26, 0);
//     int i = 0, j = 0, len = 0, max_len = INT_MIN;
//     while (j < s.size())
//     {
//         set[s[j] - 'a']++;
//         while (set[s[j] - 'a'] > 1)
//         {
//             set[s[i] - 'a']--;
//             i++;
//         }
//         len = j - i + 1;
//         max_len = max(max_len, len);
//         j++;
//     }
//     return max_len == INT_MIN ? 0 : max_len;
// }

int lengthOfLongestSubstring(string s)
{
    // vector<int> set(26,0);
    unordered_set<char> set;
    int i = 0, j = 0, len = 0, max_len = INT_MIN;
    while (j < s.size())
    {
        if (set.find(s[j]) == set.end())
        {
            set.insert(s[j]);
            max_len = max(max_len, j - i + 1);
            j++;
            
        }
        else
        {
            while (set.find(s[j]) != set.end())
            {
                set.erase(s[i]);
                i++;
            }
        }
    }
    return max_len == INT_MIN ? 0 : max_len;
}

int main()
{
    string s = "bbbabcdddd";
    cout << lengthOfLongestSubstring(s);
}