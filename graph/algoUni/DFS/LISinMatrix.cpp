#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long dfs(vector<vector<long long>> &mat, long long x, long long y, vector<vector<long long>> &lis)
{
    if (lis[x][y] != 0)
    {
        return lis[x][y];
    }
    long long n = mat.size();
    long long m = mat[0].size();
    long long ans = 1;
    if (x - 1 >= 0 && mat[x - 1][y] > mat[x][y])
    {
        ans = max(ans, 1 + dfs(mat, x - 1, y, lis));
    }
    if (x + 1 < n && mat[x + 1][y] > mat[x][y])
    {
        ans = max(ans, 1 + dfs(mat, x + 1, y, lis));
    }
    if (y - 1 >= 0 && mat[x][y - 1] > mat[x][y])
    {
        ans = max(ans, 1 + dfs(mat, x, y - 1, lis));
    }
    if (y + 1 < m && mat[x][y + 1] > mat[x][y])
    {
        ans = max(ans, 1 + dfs(mat, x, y + 1, lis));
    }
    lis[x][y] = ans;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m;
    cin >> n >> m;
    vector<vector<long long>> mat(n, vector<long long>(m));
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    vector<vector<long long>> dist(n, vector<long long>(m, 0));
    long long ans = 0;
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < m; j++)
        {
            ans = max(ans, dfs(mat, i, j, dist));
        }
    }
    cout << ans << endl;
}