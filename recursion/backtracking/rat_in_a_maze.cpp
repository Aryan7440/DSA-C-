#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void display(vector<vector<int>> &m)
    {
        for (int i = 0; i < m.size(); i++)
        {
            for (int j = 0; j < m[j].size(); j++)
            {
                cout << m[i][j];
            }
        }
    }
    bool check(int x, int y, vector<vector<int>> &mp, vector<vector<int>> &m)
    {
        if (m[x][y] == 0)
            return false;
        if (mp[x][y] = 1)
            return false;
        if (x < 0 || x >= mp.size() || y < 0 || y >= mp.size())
            return false;
        return true;
    }

    void find(vector<vector<int>> &m, int n, int x, int y, vector<vector<int>> &mp, vector<string> &ans, string s)
    {
        if (x == n - 1 && y == n - 1)
        {

            // display(m);
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << endl;
            }
            return;
        }
        if (check(x, y + 1, mp, m))
        {
            mp[x][y + 1]++;
            find(m, n, x, y + 1, mp, ans, s + 'D');
            mp[x][y]--;
        }
        if (check(x + 1, y, mp, m))
        {
            mp[x + 1][y]++;
            find(m, n, x + 1, y, mp, ans, s + 'R');
            mp[x + 1][y]--;
        }
        if (check(x, y - 1, mp, m))
        {
            mp[x][y - 1]++;
            find(m, n, x, y - 1, mp, ans, s + 'U');
            mp[x][y - 1]--;
        }
        if (check(x, y + 1, mp, m))
        {
            mp[x - 1][y]++;
            find(m, n, x - 1, y, mp, ans, s + 'L');
            mp[x - 1][y]--;
        }
    }
    // vector<string> findPath(vector<vector<int>> &m, int n)
    // {
    //     // Your code goes here
    // }
};
bool check(int x, int y, vector<vector<int>> &mp, vector<vector<int>> &m)
{
    if (x < 0 || x >= mp.size() || y < 0 || y >= mp.size())
        return false;
    if (m[x][y] == 0)
        return false;
    if (mp[x][y] == 1)
        return false;
    
    return true;
}

void find(vector<vector<int>> &m, int n, int x, int y, vector<vector<int>> &mp, vector<string> &ans, string s)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(s);
        return;
    }
    if (check(x, y + 1, mp, m))
    {
        mp[x][y]=1;
        find(m, n, x, y + 1, mp, ans, s + 'R');
        mp[x][y]=0;
    }
    if (check(x + 1, y, mp, m))
    {
        mp[x][y]=1;
        find(m, n, x + 1, y, mp, ans, s + 'D');
        mp[x][y]=0;
    }
    if (check(x, y - 1, mp, m))
    {
        mp[x][y]=1;
        find(m, n, x, y - 1, mp, ans, s + 'L');
        mp[x][y]=0;
    }
    if (check(x-1, y , mp, m))
    {
        mp[x][y]=1;
        find(m, n, x - 1, y, mp, ans, s + 'U');
        mp[x][y]=0;
    }
}

int main()
{
    // vector<vector<int>> m = {{1, 0, 0, 0},
    //                          {1, 1, 0, 1},
    //                          {1, 1, 0, 0},
    //                          {0, 1, 1, 1}};
    vector<vector<int>> m = {{0 ,1, 1, 1},{ 1, 1, 1, 0},{ 1, 0, 1, 1},{ 0, 0, 1, 1}};
    // vector<vector<int>> mp(4, vector<int>(4, 0));
    // vector<string> ans;
    // string s;
    // find(m,4,0,0,mp,ans,s);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout<<ans[i]<<endl;
    // }
    

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
}