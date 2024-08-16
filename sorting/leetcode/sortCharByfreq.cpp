#include <bits/stdc++.h>
using namespace std;
static bool comp(pair<int, char> &p1, pair<int, char> &p2)
{
    return p1.first > p2.first;
}
string frequencySort(string s)
{
    vector<pair<int, char>> mp(26);
    for (auto i : s)
    {
        mp[i - 'a'].first += 1;
        mp[i - 'a'].second = i;
    }
    sort(mp.begin(), mp.end(), comp);
    string ans;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < mp[i].first; j++)
        {
            ans.push_back(mp[i].second);
        }
    }
    return ans;
}
int main()
{
    string s = "cccaaa";
    cout << frequencySort(s);
}