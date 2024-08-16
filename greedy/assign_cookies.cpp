#include <bits/stdc++.h>
using namespace std;
int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0, j = 0;
    int ans = 0;
    while (i < g.size() && j < s.size())
    {
        if (g[i] <= s[j])
        {
            i++;
            j++;
            ans++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> s={10,9,8,7};
    vector<int> g={10,9,8,7};
    cout<<findContentChildren(g,s);
}