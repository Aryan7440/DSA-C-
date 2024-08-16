#include <bits/stdc++.h>
using namespace std;
string reorganizeString(string s)
{
    unordered_map<char, int> mp;
    for (auto c : s)
        mp[c]++;
    priority_queue<pair<int, char>> pq;
    for (auto i : mp)
        pq.push({i.second, i.first});
    string ans;
    while (ans.size() < s.size())
    {
        pair<int, char> p1 = pq.top();
        pq.pop();
        pair<int, char> p2 = {-1, '*'};
        if (!pq.empty())
        {
            p2 = pq.top();
            pq.pop();
        }
        ans.push_back(p1.second);
        p1.first = p1.first - 1;
        if (p2.first == -1 && p1.first > 0)
            return "";
        if (p2.first != -1)
        {
            ans.push_back(p2.second);
            p2.first = p2.first - 1;
        }
        if (p1.first != 0)
            pq.push(p1);
        if (p2.first != 0 && p2.first != -1)
            pq.push(p2);
    }
    return ans;
}

int main()
{
    string a = "aab";
    cout << reorganizeString(a);
}