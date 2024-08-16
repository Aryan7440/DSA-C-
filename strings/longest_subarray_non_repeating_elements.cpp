#include <iostream>
#include <string>
#include <vector>
#include<unordered_map>
using namespace std;

int longest_subarray(string s)
{
    int length = 0;
    int start = 0;
    vector<int> index(26, -1);
    for (int i = 0; i < s.size(); i++)
    {
        start = max(start, index[s[i] - 'a'] + 1);
        length = max(length, i - start + 1);
        index[s[i] - 'a'] = i;
    }
    return length;
}

int longest_substring(string s)
{
    vector<int> v(26, -1);
    int i = 0;
    int j = 0;
    int count = 0;
    int Mcount = 0;
    while (j < s.size())
    {
        i = max(i, v[s[j] - 'a'] + 1);
        count = max(count, j - i + 1);
        v[s[j] - 'a'] = j;
        j++;
    }
    return count;
}

int ls(string s)
{
    int i = 0, j = 0;
    unordered_map<char,int> mp;
    int len=0;
    while (j < s.size())
    {
        i=max(i,mp[s[j]]+1);
        len=max(len,j-i+1);
        mp[s[j]]=j;
        j++;
    }
    return len;
}
int main()
{
    string str = "geeksfomrmngeeks";
    // cout<<longest_subarray(str);
    cout << ls(str);
    // cout << longest_substring(str);
}