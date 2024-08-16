#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fill(vector<vector<int>> mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> ans(m + n - 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans[i - j + m - 1].push_back(mat[i][j]);
        }
    }
    return ans;
}

void display(vector<vector<int>> mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> ans(m + n - 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
vector<queue<int>> srt(vector<vector<int>> &mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        sort(mat[i].begin(), mat[i].end());
    }
    vector<queue<int>> a;
    for (int i = 0; i < mat.size(); i++)
    {
        queue<int> temp;
        for (int j = 0; j < mat[i].size(); j++)
        {
            temp.push(mat[i][j]);
        }
        a.push_back(temp);
    }
    return a;
}

vector<vector<int>> fill2(vector<queue<int>> a, int n, int m)
{
    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans[i][j] = a[i - j + m - 1].front();
            a[i - j + m - 1].pop();
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> v = {{3, 3, 1, 1}, {2, 2, 1, 2}, {1, 1, 1, 2}};
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            mp[i - j].push_back(v[i][j]);
        }
    }
    int n=v.size(),m=v[0].size();
    for (int i = -(m-1); i < n; i++)
    {
        sort(mp[i].begin(),mp[i].end());
    }
    for (int i = v.size()-1; i >=0; i--)
    {
        for (int j = v[0].size()-1; j >=0; j--)
        {
            v[i][j]=mp[i-j].back();
            mp[i-j].pop_back();
        }
        
    }
    display(v);
    
    
}