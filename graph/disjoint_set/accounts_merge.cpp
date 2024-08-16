#include <bits/stdc++.h>
using namespace std;
class DSU
{
public:
    unordered_map<int, int> parent, size;
    int count = 0;
    int find(int x)
    {
        if (parent.find(x) == parent.end())
        {
            parent[x] = x;
            size[x]++;
            // count++;
        }
        if (parent[x] != x)
        {
            return parent[x] = find(parent[x]);
        }
        return x;
    }
    void join(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if (px == py)
            return;
        else
        {
            count--;
            if (size[px] > size[py])
            {
                parent[py] = px;
                size[py] += size[px];
            }
            else
            {
                parent[px] = py;
                size[px] += size[py];
            }
        }
    }
};
vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    DSU a;
    unordered_map<int, string> label;
    for (int i = 0; i < accounts.size(); i++)
    {
        label[i] = accounts[i][0];
        a.find(i);
    }

    unordered_map<string, int> set;
    for (int i = 0; i < accounts.size(); i++)
    {
        // a.find(i);
        for (int j = 1; j < accounts[i].size(); j++)
        {
            if (set.find(accounts[i][j]) == set.end())
            {
                set[accounts[i][j]] = i;
            }
            else
            {
                a.join(i,set[accounts[i][j]] );
                set[accounts[i][j]] = i;
            }
        }
    }
    vector<string> li[accounts.size()];
    for(auto i:set)
    {
        int par=a.find(i.second);
        li[par].push_back(i.first);
    }

    vector<vector<string>> ans;
    for(int i=0;i<accounts.size();i++)
    {
        if(li[i].size()==0)continue;
        vector<string> temp;
        temp.push_back(label[i]);
        sort(label[i].begin(),label[i].end());
        for(int j=0;j<li[i].size();j++)temp.push_back(li[i][j]);
        ans.push_back(temp);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int main()
{
    vector<vector<string>> accounts = {{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
     {"John", "johnsmith@mail.com", "john00@mail.com"}, 
     {"Mary", "mary@mail.com"}, 
     {"John", "johnnybravo@mail.com"}};
    vector<vector<string>> ans = accountsMerge(accounts);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}